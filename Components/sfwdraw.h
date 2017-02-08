#pragma once

/***************************************

For use in AIE Year 1 Programming Classes.

This namespace is SUITED FOR WORK.

This framework is intended to provide a simple, modern implementation of OpenGL for educational use.
It can, primarily, load textures and sprite atlases (when given rows/cols). It does NOT use depth testing (no Z-ordering),
but does allow for transparency. This means that the order in which draw calls are made matters.
The default projection uses pixel-perfect screen coordinates, with 0,0 at the bottom left.

Where applicable, Colors use HEX values in RGBA format (0xRRGGBBAA)-> like html.
Where applicable, transformation matrix parameters are treated as parent matrices (pre-multiplied by other parameters).
Where applicable, 'centered' parameters indicate whether the image and transforms will occur from the center, or TOP-LEFT.



Contact me for more details/examples/explanations.
Author: Esmeralda Salamone, esmes@aie.edu.au

Uses GLFW (release for all configs), GLM, STB, and opengl loader generator.
For to whomever cares, this only link

NOTE: YOU MUST CALL initContext for any of the functions to work!

************************/


#define KEY_ESCAPE    256
#define KEY_ENTER	  257
#define KEY_TAB		  258
#define KEY_BACKSPACE 259

#define KEY_RIGHT     262
#define KEY_LEFT	  263
#define KEY_DOWN	  264
#define KEY_UP		  265

#define MOUSE_BUTTON_RIGHT	1
#define MOUSE_BUTTON_LEFT	0

#define GAMEPAD_DEADZONE_THRESHOLD 0.25f

#define XBOX360_AXIS_LSTICK_HORIZONTAL	0
#define XBOX360_AXIS_LSTICK_VERTICAL	1
#define XBOX360_AXIS_TRIGGERS			2
#define XBOX360_AXIS_RSTICK_HORIZONTAL	3
#define XBOX360_AXIS_RSTICK_VERTICAL	4

#define XBOX360_BUTTON_A			0
#define XBOX360_BUTTON_B			1
#define XBOX360_BUTTON_X			2
#define XBOX360_BUTTON_Y			3
#define XBOX360_BUTTON_L			4
#define XBOX360_BUTTON_R			5

#define XBOX360_BUTTON_BACK			6
#define XBOX360_BUTTON_START		7

#define XBOX360_BUTTON_LSTICK		8
#define XBOX360_BUTTON_RSTICK		9

#define XBOX360_DPAD_UP				10
#define XBOX360_DPAD_RIGHT			11
#define XBOX360_DPAD_DOWN			12
#define XBOX360_DPAD_LEFT			13






#define WHITE	 0xffffffff
#define BLACK    0x000000ff
#define CYAN	 0x00ffffff
#define MAGENTA  0xff00ffff
#define YELLOW	 0xffff00ff
#define RED		 0xff0000ff
#define GREEN    0x00ff00ff
#define BLUE	 0x0000ffff
#define NONE     0x00000000

#define PI 3.14159265359

namespace sfw
{
	
	const float identity[16] = {1,0,0,0,  0,1,0,0, 0,0,1,0, 0,0,0,1};

    const float identity3[9] = { 1,0,0,  0,1,0, 0,0,1};

	
	
	
	
	unsigned loadTextureMap(const char* path, unsigned rows = 1, unsigned cols = 1);
	
	unsigned getTextureWidth(unsigned handle);
	
	unsigned getTextureHeight(unsigned handle);
	
	
	
	
	
	
	
	
	
	
	void drawTexture(unsigned handle, float x, float y, float width = 1, float height = 1, float angle = 0, bool centered = true, unsigned index = 0, unsigned int tint = WHITE, const float transform[16] = identity);
	
	
	
	
	
	
	void drawTextureMatrix(unsigned handle, unsigned index = 0, unsigned int tint = WHITE, const float transform[16] = identity);
	

    
    
    
    
    
    
    void drawTextureMatrix3(unsigned handle, unsigned index=0, unsigned int tint=WHITE, const float transform[9]=identity3, float z=0);



	
	
	
	
	
	
	
	
	
	
	
	void drawString(unsigned handle, const char *text, float x, float y, float width = 1, float height = 1, float angle = 0, char offset = '\0', unsigned int tint = WHITE, const float transform[16] = identity);

	
	
	
	void drawLineMatrix(unsigned tint = WHITE, const float transform[16] = identity);

	
	
	
	
	void drawLine(float x1, float y1, float x2, float y2, unsigned tint = 0xffffffff, const float transform[16] = identity);

    
    
    
    
    
    void drawLine3(float x1, float y1, float x2, float y2, float z, unsigned tint, const float transform[9] = identity3);

	
	
	
	
	
	
	void drawCircle(float x, float y, float radius, unsigned steps = 12, unsigned tint = 0xffffffff, const float transform[16] = identity);

	
	
	
	
	bool initContext(unsigned width = 800, unsigned height = 600, const char *title = "SFW Draw");
	
	
	void termContext();
	
	
	bool stepContext();

	
	void setBackgroundColor(unsigned int tint);

	
	
	void setProjectionMatrix(const float transform[16]);

	
	
	void setViewMatrix(const float transform[16]);

	
	bool getKey(unsigned keycode);

	
	bool getMouseButton(unsigned mousekeycode);
	
	
	float getMouseX();
	
	float getMouseY();

	
	float getTime();

	
	
	
	float getDeltaTime();


	
	
	
	
	

	
	bool		getGamepadPresent(unsigned gamepadIndex);

	
	const char *getGamepadName(unsigned gamepadIndex);
	
	
	
	unsigned	getNumGamepadAxis(unsigned gamepadIndex);
	
	
	unsigned	getNumGamepadButtons(unsigned gamepadIndex);

	
	float		getGamepadAxis(unsigned gamepadIndex, unsigned axisIndex, float deadzone = GAMEPAD_DEADZONE_THRESHOLD);

	
	bool		getGamepadButton(unsigned gamepadIndex, unsigned buttonIndex);





}
