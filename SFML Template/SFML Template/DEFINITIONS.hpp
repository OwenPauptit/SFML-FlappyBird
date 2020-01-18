#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 400.0f
#define FLYING_SPEED 500.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 200.f
#define MAXIMUM_ROTATION 25.0f

#define BIRD_PIPE_COLLISION_SCALE 0.625f // scale of bird rect when colliding with a pipe
#define BIRD_LAND_COLLISION_SCALE 0.7f // scale of bird rect when colliding with land
#define PIPE_COLLISION_SCALE 1.0f
#define LAND_COLLISION_SCALE 1.0f

#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define SPLASH_SCREEN_BACKGROUND_FILEPATH "Resources/Images/AeselStudiosSplashScreen.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/Images/sky.png"
#define GAME_BACKGROUND_FILEPATH "Resources/Images/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/Images/sky.png"

#define GAME_TITLE_FILEPATH "Resources/Images/title.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/Images/GameOverTitle.png"
#define GAME_OVER_BODY_FILEPATH "Resources/Images/GameOverBody.png"
#define PLAY_BUTTON_FILEPATH "Resources/Images/PlayButton.png"
#define PIPE_UP_FILEPATH "Resources/Images/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/Images/PipeDown.png"
#define SCORING_PIPE_FILEPATH "Resources/Images/InvisibleScoringPipe.png"
#define LAND_FILEPATH "Resources/Images/land.png"

#define BIRD_FRAME_1_FILEPATH "Resources/Images/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/Images/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/Images/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/Images/bird-04.png"

#define FLAPPY_FONT_FILEPATH "Resources/Fonts/FlappyFont.ttf"
#define FLAPPY_FONT_SIZE 128
#define GAME_OVER_SCORE_SIZE 56


// The three states while playing
enum GameStates {
	eReady, // before the player starts tapping, only bird animation and land movement
	ePlaying, // while the player is tapping, pipes spawn and bird can fly
	eGameOver // after the player has collided with pipe or land
};
