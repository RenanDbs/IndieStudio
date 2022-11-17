/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Entity
*/

#include "IndieStudio.hpp"

void IndieStudio::stockCSVMenuInVec()
{
    std::string Filename = "Texture/box.csv";
    // std::string Filename = "Texture/nobox.csv";
    std::vector<int> CSVrow;
    std::string line;
    std::string word;


    std::ifstream file(Filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            CSVrow.clear();
            std::stringstream str(line);
            while (getline(str, word, ','))
            {
                CSVrow.push_back(atoi(word.c_str()));
            }
            _CsvBox.push_back(CSVrow);
        }
    }
    else
        std::cout << "Can't read file" << std::endl;
}

std::vector<std::vector<int>> IndieStudio::getCsvBox() {
    return _CsvBox;
}

Entity create_box() {
    IndieStudio indiestudio;
    indiestudio.stockCSVMenuInVec();
    std::vector<std::vector<int>> csvBox = indiestudio.getCsvBox();
    struct position_t position{0.0f, 0.5f, 0.0f};
    Entity entity = Entity(position);
    std::srand((unsigned int)std::time(nullptr));
    int x = 1;
    Vector3 positionBox = {-7.5f, 0.5f, -8.0f};
    std::vector<std::shared_ptr<Components::IComponent>> components;
    for (size_t i = 0; i < csvBox.size(); i++) {
        for (size_t j = 0; j < csvBox[i].size(); j++) {
            x = 1 + std::rand()/((RAND_MAX + 1u)/12);
            if (csvBox[i][j] == 1 && x > 4) {
                std::shared_ptr<Components::Shapes> square(new Components::Shapes(positionBox, 1.0, 1.0, 1.0, RAYWHITE));
                entity.setNbBox(1);
                entity.addBox(square);
                components.push_back(square);
                square->setShapes();
            }
             positionBox.x = positionBox.x + 1.0f;
        }
        positionBox.z = positionBox.z + 1.0f;
        positionBox.x = -7.5f;
    }
    entity.addComponents(components);
    return entity;
}

int IndieStudio::getOpacityTransition() {
    return _opacityTransition;
}

void IndieStudio::setOpacityTransition(int opacity) {
    _opacityTransition = opacity; 
}

void IndieStudio::setStateTransition(int state) {
    _stateTransition = state; 
}

void IndieStudio::buildFirstIntro(Draw &draw, Texture2D textureIntro) {
    if (_opacityTransition < 255 && _stateTransition == 0) {
        _opacityTransition += 1;
        draw.DrawTexture2D(textureIntro,0,0,CLITERAL(Color){245,245,245,(unsigned char)_opacityTransition});
    }
    if (_opacityTransition == 255 && _stateTransition == 0) {
        _stateTransition = 1 ;
    }
    if (_opacityTransition >= 0 && _stateTransition == 1){
        draw.DrawTexture2D(textureIntro, 0,0,CLITERAL(Color){245,245,245,(unsigned char)_opacityTransition});
        _opacityTransition-= 1;
    }
    if (_opacityTransition == 0 && _stateTransition == 1) {
        _stateTransition = 0;
    }
}

int main(void) {
    IndieStudio indie;
    Director director;
    Entity camera = director.make(EntityTypes::BASE_CAMERA, {0.0, 15.0, 10.0});
    // Entity *camera = director.make(EntityTypes::BASE_CAMERA, {0.0, 25.0, 0.0});
    Entity map = director.make(EntityTypes::MAP, {0.0, 0.5, 0.0});
    Entity player0;
    Entity player1;
    Entity player2;
    Entity player3;
    std::vector<Entity> players(4);
    int nbPlayers = -1;
    std::vector<std::shared_ptr<Components::Shapes>> bonus;
    int _winner = 0;
    int playerDead = 0;
    int resetIntroParam = 0;
    Entity box;
    std::vector<std::shared_ptr<Components::Bomb>> bombvector(0);
    Draw draw = Draw();
    
    draw.SetFlags(FLAG_WINDOW_RESIZABLE);
    draw.SetWindows(1920,1080, "IndieStudio");
    draw.setFPS(60);

    Time time;
    Sphere sphere;
    Menu menu;

    Image bg = draw.imageLoader("Texture/background.png");
    Texture2D textureBg = draw.imageToTexture(bg);
    Image end = draw.imageLoader("Texture/End.png");
    Texture2D textureEnd = draw.imageToTexture(end);
    Image imageCardBlue = draw.imageLoader("Texture/CardBlue.png");
    Texture2D textureCardBlue = draw.imageToTexture(imageCardBlue);
    Image imageCardYellow = draw.imageLoader("Texture/CardYellow.png");
    Texture2D textureCardYellow = draw.imageToTexture(imageCardYellow);
    Image imageCardGreen = draw.imageLoader("Texture/CardGreen.png");
    Texture2D textureCardGreen = draw.imageToTexture(imageCardGreen);
    Image imageCardRed = draw.imageLoader("Texture/CardRed.png");
    Texture2D textureCardRed = draw.imageToTexture(imageCardRed);
    Image imageIntro = draw.imageLoader("Texture/Intro.png");
    Texture2D textureIntro = draw.imageToTexture(imageIntro);
    Image imageIntro2 = draw.imageLoader("Texture/Intro2.png");
    Texture2D textureIntro2 = draw.imageToTexture(imageIntro2);

    map.getShapesComp()->setMap();
    map.getShapesComp()->setShapes();

    GameState gameState = INTRO;
    menu.PlayMusic();
    while (!draw.isClosed()) {
        draw.StartDraw();
        draw.MyClearBackground();
        switch(gameState)
        {
            case INTRO:
                if (IsKeyPressed(KEY_SPACE))
                    gameState = INTRO2;
                if (indie.getOpacityTransition() != 0) {
                    indie.buildFirstIntro(draw, textureIntro);
                } else
                    gameState = INTRO2;
            break;
            case INTRO2:
                if (IsKeyPressed(KEY_SPACE))
                    gameState = MENU;
                if (resetIntroParam == 0) {
                    indie.setOpacityTransition(1);
                    indie.setStateTransition(0);
                    resetIntroParam++;
                }
                if (indie.getOpacityTransition() != 0) {
                    indie.buildFirstIntro(draw, textureIntro2);
                } else {
                    time.SetCurrentTime();
                    gameState = MENU;
                }
            break;
            case MENU:
                draw.MyClearBackground();
                menu.DrawMenu();
                if (time.CheckTime(15))
                    nbPlayers = 0;
                if (nbPlayers == 0 || ((nbPlayers = menu.CheckMenu()) != -1 && nbPlayers != 5)) {
                    player0 = director.make(EntityTypes::PLAYER0, {-6.5f, 0.2f, 6.0f});  // PURPLE
                    player1 = director.make(EntityTypes::PLAYER1, {-6.5f, 0.2f, -7.0f}); // RED
                    player2 = director.make(EntityTypes::PLAYER2, {6.5f, 0.0f, 6.0f}); // GREEN
                    player3 = director.make(EntityTypes::PLAYER3, {6.50f, 0.0f, -7.0f}); // YELLOW
                    players = {player0, player1, player2, player3};
                    for (int i = 0; i < 4; i++)
                        players[i].getBombComp()->setTextBomb();
                    box = create_box();
                    players[0].getObjectComp()->setMod("Texture/player_gametoons/sceneblue.gltf");
                    players[1].getObjectComp()->setMod("Texture/player_gametoons/scenered.gltf");
                    players[2].getObjectComp()->setMod("Texture/player_gametoons/scenegreen.gltf");
                    players[3].getObjectComp()->setMod("Texture/player_gametoons/sceneyellow.gltf");
                    map.getShapesComp()->setMap();
                    map.getShapesComp()->setShapes();
                    
                    std::cout << "nb players: " << nbPlayers << std::endl;
                    for (int i = 3; i >= nbPlayers; i--) {
                        std::shared_ptr<Components::Ia> iaComp(new Components::Ia(i));
                        players[i].addComponents({iaComp});
                        players[i].getIAComp();
                    }
                    gameState = GAME;
                }
                if (nbPlayers == 5) {
                    gameState = OPTIONS;
                }
            break;
            case GAME:
                draw.MyClearBackground();
                draw.DrawTexture2D(textureBg, 0, 0, WHITE);

                draw.DrawTexture2D(textureCardBlue, 100, 300, WHITE);
                draw.DrawTexte(std::to_string(players[0].getObjectComp()->getSpeed()).substr(0, 4).c_str(), 280, 346, 17);
                draw.DrawTexte(std::to_string(players[0].getObjectComp()->getPower()).substr(0, 3).c_str(), 280, 370, 17);
                draw.DrawTexture2D(textureCardYellow, 1500, 40, WHITE);
                draw.DrawTexte(std::to_string(players[1].getObjectComp()->getSpeed()).substr(0, 4).c_str(), 1680, 86, 17);
                draw.DrawTexte(std::to_string(players[1].getObjectComp()->getPower()).substr(0, 3).c_str(), 1680, 110, 17);
                draw.DrawTexture2D(textureCardGreen, 1500, 300, WHITE);
                draw.DrawTexte(std::to_string(players[2].getObjectComp()->getSpeed()).substr(0, 4).c_str(), 1680, 346, 17);
                draw.DrawTexte(std::to_string(players[2].getObjectComp()->getPower()).substr(0, 3).c_str(), 1680, 370, 17);
                draw.DrawTexture2D(textureCardRed, 100, 40, WHITE);
                draw.DrawTexte(std::to_string(players[3].getObjectComp()->getSpeed()).substr(0, 4).c_str(), 280, 86, 17);
                draw.DrawTexte(std::to_string(players[3].getObjectComp()->getPower()).substr(0, 3).c_str(), 280, 110, 17);
                draw.StartDraw3D(camera.getCameraComp());
                
                for (int i = 0; i < 4; i++) {
                    std::shared_ptr<Components::Object> playerObjectComp= players[i].getObjectComp();
                    std::vector<std::shared_ptr<Components::Object>> playerObject {players[0].getObjectComp(), players[1].getObjectComp(), players[2].getObjectComp(), players[3].getObjectComp()};
                    std::vector<std::shared_ptr<Components::Shapes>> boxes = box.getBoxVec();
                    if (playerObjectComp->getHealth() != 0) {
                        std::cout << "joueur " << i << " en vie" << std::endl;
                        playerObjectComp->drawObject();
                        try {
                            // players[i].getIAComp()->moveIA(players, i, map, box, box.getBoxVec(), bombvector);
                            if (players[i].getIAComp()->moveIA(players, i, map, box, box.getBoxVec(), bombvector) == direction::POSE_BOMB)
                                players[i].getBombComp()->setPoseBomb(true);
                        } catch (char const *errMessage) {
                            players[i].getMovementComp()->getMovementObject(playerObjectComp, players[i].getCollisionComp(), map.getShapesComp(), box.getBoxVec(), box.getnbBox());
                        }
                        bonus = players[i].getBombComp()->spawnBomb(players[i].getBombComp()->setBomb(playerObjectComp), playerObject, boxes, box.getnbBox(), bonus, playerObjectComp->getPower(), bombvector, menu, draw, sphere);
                    }
                }

                map.getShapesComp()->drawMap();
                for (size_t i = 0; i < box.getnbBox(); i++) {
                    if (box.getBoxComp((int)i)->isPrintable() == 1)
                        box.getBoxComp((int)i)->drawShape();
                }

                for (size_t i = 0; i < bonus.size(); i++) {
                    // Vector3 bonusPosition = bonus[i]->getPosition();
                    if (bonus[i]->getPosition().y >= 0.59f && bonus[i]->getUp() == 0) {
                        bonus[i]->setPositionY(-0.01f);
                        bonus[i]->drawShape();
                        if (bonus[i]->getPosition().y <=0.6f)
                            bonus[i]->setUp(1);
                    }
                    if (bonus[i]->getPosition().y <= 1.0f && bonus[i]->getUp() == 1) {
                        bonus[i]->setPositionY(0.01f);
                        bonus[i]->drawShape();
                        if (bonus[i]->getPosition().y >=1.0f)
                            bonus[i]->setUp(0);  
                    }
                }

                for (size_t i = 0; i < bonus.size(); i++) {
                    for (int j = 0; j < 4; j++) {
                        std::shared_ptr<Components::Object> playerObjectComp = players[j].getObjectComp();
                        if (CheckCollisionSpheres(bonus[i]->getPosition(), 0.4f, playerObjectComp->getPos3D(), 0.4f) && bonus[i]->getBonusType() == 1) {
                            playerObjectComp->setSpeed(0.01f);
                            bonus.erase(bonus.begin() + i);
                        }
                        if (CheckCollisionSpheres(bonus[i]->getPosition(), 0.4f, playerObjectComp->getPos3D(), 0.4f) && bonus[i]->getBonusType() == 2) {
                            playerObjectComp->setPower(0.5f);
                            bonus.erase(bonus.begin() + i);
                        }
                    }
                }

                draw.EndDraw3D();

                map.getShapesComp()->drawMinMap(players[0].getObjectComp(), players[1].getObjectComp(), players[2].getObjectComp(), players[3].getObjectComp(), map.getShapesComp());

                for (int i = 0; i < 4; i++) {
                    playerDead = 0;
                    for (int j = 0; j < 4; j++) {
                        if (i != j && players[i].getObjectComp()->getHealth() == 1 && players[j].getObjectComp()->getHealth() == 0) {
                            playerDead ++;
                            _winner = i + 1;
                        }
                    }
                    if (playerDead == 3)
                        gameState = END;
                }
            break;
            case OPTIONS:
                draw.MyClearBackground();
                if (menu.DrawOptions()) {
                    time.SetCurrentTime();
                    gameState = MENU;
                }
                menu.PauseMusic();
            break;
            case END:
                draw.MyClearBackground();
                draw.DrawTexture2D(textureEnd, 0, 0, WHITE);
                menu.DrawEnd(_winner);
                menu.DrawEndMenu();

                if (menu.CheckMenu() == 4) {
                    bonus.clear();
                    _winner = 0;
                    time.SetCurrentTime();
                    gameState = MENU;
                }
                if (menu.CheckMenu() == 5) {
                    _winner = 0;
                    bonus.clear();
                    gameState = OPTIONS;
                }
            break;
        }
        draw.EndDraw();
    }
    draw.MyCloseWindow();
    // delete camera;
    return 0;
}
