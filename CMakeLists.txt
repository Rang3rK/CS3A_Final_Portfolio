cmake_minimum_required(VERSION 3.26)
project(finalportfolio)

set(CMAKE_CXX_STANDARD 20)

add_executable(finalportfolio main.cpp
        Button.h
        Button.cpp
        States.h
        States.cpp
        StateEnum.h
        Project.cpp
        Project.h
        Portfolio.cpp
        Portfolio.h
        Runable.h
        Runable.cpp
        Updateable.cpp
        Updateable.h
        EventHandlerable.cpp
        EventHandlerable.h
        Font.cpp
        Font.h
        MouseEvent.h
        MouseEvent.cpp
        Position.h
        Position.cpp
        GreenCircle.cpp
        GreenCircle.h
        BouncingBall.h
        BouncingBall.cpp
        Ball.cpp
        Nameable.cpp
        Circle.cpp
        RPN.cpp
        Background.h
        Background.cpp
        Calculator.cpp
        Display.cpp
        ProgramCal.cpp
        ProgramCal.h
        Clock.cpp
        Deck.cpp
        Card.cpp
        CardGraphics.cpp
        CardHand.cpp
        CardHandScorer.cpp
        image.h
        image.cpp
        LetterBox.cpp
        PokerDisplay.cpp
        scoreText.cpp
        ScoreCard.cpp
        Screen.cpp
        Snake.cpp
        SnakeFunction.cpp
        SnakeGame.cpp
        Fruit.cpp
)

target_link_libraries(finalportfolio sfml-graphics sfml-audio)

find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)