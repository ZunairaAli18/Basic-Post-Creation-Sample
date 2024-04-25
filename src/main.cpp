#include <iostream>
#include <raylib.h>
using namespace std;
const int width = 800;
const int height = 600;

int main() {
   InitWindow(width, height,"My First Raylib Program");
    Texture2D texture=LoadTexture("assets/image.png");
    int textwidth=65;
    int textX=20+(90-textwidth)/2;
    int textY=550/2 + (50-15)/2;
   Rectangle buttonRec={20,550/2,80,50};
   Rectangle source={textX,textY,textwidth,18};
   Rectangle openRec = {220, 80, 300, 400};
   Rectangle rec1={226,103,288,200};
   Rectangle buttonPost={455,435,60,30};
   Rectangle crossbutton={490,82,30,20};
   bool buttonPressed=false;
   bool rec=false;
   bool posted=false;
   bool crosspressed=false;
   bool postpressed=false;
   SetTargetFPS(60);

   while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);
    if(CheckCollisionPointRec(GetMousePosition(),buttonRec)){
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        buttonPressed=true;
        rec=true;
      }
      else{
         buttonPressed=false;
      }
    }
    
    if(CheckCollisionPointRec(GetMousePosition(),buttonPost)){
      postpressed=true;
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
       posted=true;
      }
      }
      else{
        postpressed=false;
      }
      
    if(CheckCollisionPointRec(GetMousePosition(),crossbutton)){
      
      crosspressed=true;
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        rec=false;
        crosspressed=false;
        postpressed=false;
        posted=false;
      }
    }
    else{
      crosspressed=false;
    }
    
     //Drawing button
    DrawRectangleRec(buttonRec,buttonPressed?MAROON : LIGHTGRAY);
    DrawTextureEx(texture,(Vector2){(float)textX+13,(float)textY-5},0,0.06,WHITE);
   // DrawTexturePro(texture,(Rectangle){textX,textY,texture.width,texture.height},source,(Vector2){0,0},0,WHITE);
    if(rec){
      DrawRectangleRec(openRec,WHITE);
      DrawRectangleLinesEx(openRec,2,BLACK);
      DrawRectangleRec(rec1,LIGHTGRAY);
      DrawRectangleLinesEx(rec1,2,BLACK);
      DrawRectangleRec(buttonPost,postpressed || posted?MAROON : LIGHTGRAY);
      DrawText(posted?"POSTED":"POST",posted?462:464,441,13,BLACK);
      DrawRectangleLinesEx(buttonPost,2,BLACK);
      DrawRectangleRec(crossbutton,crosspressed?RED:LIGHTGRAY);
      DrawText("X",499,83,16,BLACK);
      DrawRectangleLinesEx(crossbutton,2,BLACK);
    }
    
    EndDrawing();
   }
    
     CloseWindow();
   return 0;
   }
  
