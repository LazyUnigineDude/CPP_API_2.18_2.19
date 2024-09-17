#include "Widgets.h"
REGISTER_COMPONENT(Widgets);

void Widgets::Init() {

	// Label
	Label = Unigine::WidgetLabel::create("HELLO TO GUI");
	Label->setFontSize(21);
	Label->setFontColor(Unigine::Math::vec4_red);
	Label->setFontOutline(2);
	Label->setPosition(50, 50);
	Label->getEventEnter().connect(EC, []() {Unigine::Log::message("HI\n"); });
	Label->getEventLeave().connect(EC, []() {Unigine::Log::message("BI\n"); });
	
	// Button
	Button = Unigine::WidgetButton::create("Click Me");
	Button->setWidth(50);
	Button->setFontSize(21);
	Button->setPosition(400, 400);
	Button->setFontColor(Unigine::Math::vec4_red);
	Button->setButtonColor(Unigine::Math::vec4_black);
	Button->setOrder(1);

	Button->getEventClicked().connect(EC, &Clicked);
	Button->getEventEnter().connect(this, &Widgets::Enter);
	Button->getEventLeave().connect(this, &Widgets::Leave);

	// Slider
	Slider = Unigine::WidgetSlider::create(0, 100, 50);
	Slider->setOrientation(0);
	Slider->setHeight(250);
	Slider->setButtonHeight(100);
	Slider->setPosition(100, 150);
	Slider->setButtonColor(Unigine::Math::vec4_blue);
	Slider->getEventChanged().connect(EC, [&]() {Unigine::Log::message("Value Slider: %d\n", Slider->getValue()); });

	// Canvas
	Canvas = Unigine::WidgetCanvas::create();
	Canvas->setPosition(400, 400);

	int Square = Canvas->addPolygon(); // 200, 200
	Canvas->setPolygonColor(Square, Unigine::Math::vec4_green);
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3_zero);
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3_right * 200);
	Canvas->addPolygonPoint(Square, (Unigine::Math::vec3_right + Unigine::Math::vec3_forward) * 200);
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3_forward * 200);

	int Line = Canvas->addLine();
	Canvas->setLineColor(Line, Unigine::Math::vec4_red);
	Canvas->addLinePoint(Line, Unigine::Math::vec2( 10, 100));
	Canvas->addLinePoint(Line, Unigine::Math::vec2( 50, 150));

	int Text = Canvas->addText();
	Canvas->setTextSize(Text, 26);
	Canvas->setTextText(Text, "Hello");
	Canvas->setTextColor(Text, Unigine::Math::vec4_blue);
	Canvas->setTextPosition(Text, Unigine::Math::vec2_one * 100); //Pos 100, 100

	// Add Image to Canvas Shape
	int Image = Canvas->addPolygon(1);	// 200x200 at pos 400, 0
	Canvas->setPolygonTexture(Image, ImageFile[0]); // HardCoding Positions

	Canvas->addPolygonPoint(Image,Unigine::Math::vec3_right * 200);	 // 200, 0
	Canvas->setPolygonTexCoord(Image,Unigine::Math::vec2_zero);		// 0, 0

	Canvas->addPolygonPoint(Image,Unigine::Math::vec3_right * 400); // 400, 0
	Canvas->setPolygonTexCoord(Image,Unigine::Math::vec2(1, 0));  //  1, 0

	Canvas->addPolygonPoint(Image, (Unigine::Math::vec3_right * 400 +Unigine::Math::vec3_forward * 200));
	Canvas->setPolygonTexCoord(Image,Unigine::Math::vec2_one);// 400, 200 & 1, 1

	Canvas->addPolygonPoint(Image, (Unigine::Math::vec3_right +Unigine::Math::vec3_forward) * 200);
	Canvas->setPolygonTexCoord(Image,Unigine::Math::vec2(0, 1));// 200, 200 & 0, 1

	// Image
	Sprite = Unigine::WidgetSprite::create();
	for (int i = 0; i < ImageFile.size(); i++)
	{
		int x = Sprite->addLayer();
		Sprite->setLayerTexture(x, ImageFile[i]);

		Unigine::Math::mat4 mat = Sprite->getLayerTransform(x);
		mat.setTranslate((Unigine::Math::vec3_left + Unigine::Math::vec3_back) * hSize);
		Sprite->setLayerTransform(x, mat);
	}
	Sprite->setPosition(500, 150);

	// Image with Shaders
	Shader = Unigine::WidgetSpriteShader::create();
	Shader->setPosition(800 - hSize, 150 - hSize);
	Shader->setTexture("white.texture");
	Shader->setWidth(hSize * 2);
	Shader->setHeight(hSize * 2);
	Shader->setMaterial(MaterialFile);

	// Video
	Unigine::ObjectGuiPtr VGui = Unigine::static_ptr_cast<Unigine::ObjectGui>(GUINode.get());
	Video = Unigine::WidgetSpriteVideo::create(/*VGui->getGui(),*/ VideoFile);
	Video->setWidth(VGui->getScreenWidth());
	Video->setHeight(VGui->getScreenHeight());
	Video->setLoop(1);
	Video->play();

	//// Best thing is to do sound and video instead of syncing
	Sound = Unigine::static_ptr_cast<Unigine::SoundSource>(SoundNode.get());
	Sound->play();
	Video->setSoundSource(Sound);

	//// Works
	//Ambience = Unigine::AmbientSource::create(SoundFile);
	//Ambience->play();
	//Ambience->setLoop(1);
	//Video->setAmbientSource(Ambience);

	// Dialog Color
	Color = Unigine::WidgetDialogColor::create();
	Color->setCloseText("Close the box my guyy");
	Color->setCancelText("Cancel the changes my dudes");
	Color->setOkText("OK Dudes we pick this");
	Color->setSizeable(1);
	//Color->setPosition(800, 400);
	Color->setWidth(200);
	Color->setHeight(200);
	Color->getEventClicked().connect(
		EC,
		[&]() { 
			if (Color->isCancelClicked()) Unigine::Log::message("Clicked Cancel\n");
			else if (Color->isOkClicked()) Unigine::Log::message("Clicked OK\n");
			else if (Color->isCloseClicked()) Unigine::Log::message("Clicked Close\n");
		}
	);

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Label, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Button, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Slider, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Canvas, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Sprite, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Shader, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	//GUI->addChild(Color, GUI->ALIGN_OVERLAP);		// Moving the color to the GUIMesh

	// Add Video to Object in World
	Unigine::GuiPtr VGUIP = VGui->getGui();
	VGUIP->addChild(Video, VGUIP->ALIGN_EXPAND | VGUIP->ALIGN_OVERLAP);

	Unigine::ObjectGuiMeshPtr mGUI = Unigine::static_ptr_cast<Unigine::ObjectGuiMesh>(GUIMeshNode.get());
	Unigine::GuiPtr mGUIP = mGUI->getGui();
	mGUIP->addChild(Color, mGUIP->ALIGN_EXPAND | mGUIP->ALIGN_OVERLAP);
}

void Widgets::Update() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_U)) RotateImage(0);
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_I)) RotateImage(1);
	

	//if (Unigine::Input::isKeyDown(Unigine::Input::KEY_J)) { Ambience->stop(); }
	//if (Unigine::Input::isKeyDown(Unigine::Input::KEY_K)) { Ambience->play(); }
	//if (Unigine::Input::isKeyDown(Unigine::Input::KEY_L)) { Ambience->stop(); Ambience->setTime(0); Ambience->play(); }
		
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_J)) { Sound->stop(); }
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_K)) { Sound->play(); }
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_L)) { Sound->stop(); Sound->setTime(0); Sound->play(); }
}

void Widgets::Shutdown() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Label)) GUI->removeChild(Label);
	if (GUI->isChild(Button)) GUI->removeChild(Button);
	if (GUI->isChild(Slider)) GUI->removeChild(Slider);
	if (GUI->isChild(Canvas)) GUI->removeChild(Canvas);
	if (GUI->isChild(Sprite)) GUI->removeChild(Sprite);
	if (GUI->isChild(Shader)) GUI->removeChild(Shader);
	if (GUI->isChild(Color)) GUI->removeChild(Color);

	if (Label) Label.deleteLater();
	if (Button) Button.deleteLater();
	if (Slider) Slider.deleteLater();
	if (Canvas) Canvas.deleteLater();
	if (Sprite) Sprite.deleteLater();
	if (Shader) Shader.deleteLater();

	// Video
	Unigine::ObjectGuiPtr VGui = Unigine::static_ptr_cast<Unigine::ObjectGui>(GUINode.get());
	Unigine::GuiPtr VGUIP = VGui->getGui();
	if (VGUIP->isChild(Video)) VGUIP->removeChild(Video);

	Unigine::ObjectGuiMeshPtr mGUI = Unigine::static_ptr_cast<Unigine::ObjectGuiMesh>(GUIMeshNode.get());
	Unigine::GuiPtr mGUIP = mGUI->getGui();
	if (mGUIP->isChild(Video)) mGUIP->removeChild(Video);
	if (Color) Color.deleteLater();

	Sound->stop();
	//Ambience->stop();
	if (Video) Video.deleteLater();
}

void Widgets::RotateImage(int clockWise) {
	
	// cos0 - sin0
	// cos0 + sin0
	// 0

	if (clockWise) 		Angle += Unigine::Game::getIFps() * 36;
	else 				Angle -= Unigine::Game::getIFps() * 36;
	Angle = Unigine::Math::clamp(Angle, 0.0f, 250.0f);

	int RPM = 10000 * (Angle / 250);
	Unigine::Log::message("RPM: %d\n", RPM);

	Unigine::Math::vec3 Piv{
		(Unigine::Math::cos(Angle * Unigine::Math::Consts::DEG2RAD) - Unigine::Math::sin(Angle * Unigine::Math::Consts::DEG2RAD)) * -hSize,
		(Unigine::Math::cos(Angle * Unigine::Math::Consts::DEG2RAD) + Unigine::Math::sin(Angle * Unigine::Math::Consts::DEG2RAD)) * -hSize,
		0
	};

	Unigine::Math::quat Rot{ 0.0f,0.0f, Angle };
	Unigine::Math::mat4 Mat{ Rot, Piv };
	Sprite->setLayerTransform(ImageFile.size(), Mat);
}