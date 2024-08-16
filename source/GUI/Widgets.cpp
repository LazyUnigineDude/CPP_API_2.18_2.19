#include "Widgets.h"
REGISTER_COMPONENT(Widgets);

void Widgets::Init() {

	//Button
	Button = Unigine::WidgetButton::create("Click Me");
	Button->setWidth(50);
	Button->setFontSize(21);
	Button->setPosition(400, 400);
	Button->setFontColor(Unigine::Math::vec4_red);
	Button->setButtonColor(Unigine::Math::vec4_black);
	Button->setOrder(1);

	Button->getEventClicked().connect(&Clicked);
	Button->getEventEnter().connect(this, &Widgets::Enter);
	Button->getEventLeave().connect(this, &Widgets::Leave);

	// Canvas
	Canvas = Unigine::WidgetCanvas::create();
	Canvas->setPosition(400, 400);

	int Square = Canvas->addPolygon(0);
	Canvas->setPolygonColor(Square, Unigine::Math::vec4_green);
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3(   0,   0, 0));
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3( 200,   0, 0));
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3(   0, 200, 0));
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3( 200, 200, 0));

	int Line = Canvas->addLine(1);
	Canvas->setLineColor(Line, Unigine::Math::vec4_red);
	Canvas->addLinePoint(Line, Unigine::Math::vec2( 10, 100));
	Canvas->addLinePoint(Line, Unigine::Math::vec2( 50, 150));

	int Text = Canvas->addText(2);
	Canvas->setTextSize(Text, 26);
	Canvas->setTextText(Text, "Hello");
	Canvas->setTextColor(Text, Unigine::Math::vec4_blue);
	Canvas->setTextPosition(Text, Unigine::Math::vec2(100, 100));

	// Image
	Sprite = Unigine::WidgetSprite::create();
	for (int i = 0; i < ImageFile.size(); i++)
	{
		int x = Sprite->addLayer();
		Sprite->setLayerTexture(x, ImageFile[i]);

		Unigine::Math::mat4 mat = Sprite->getLayerTransform(x);
		mat.setTranslate(Unigine::Math::vec3(-hSize, -hSize, 0));
		Sprite->setLayerTransform(x, mat);
	}
	Sprite->setPosition(500, 150);


	// Video
	Unigine::ObjectGuiPtr VGui = Unigine::static_ptr_cast<Unigine::ObjectGui>(GUINode.get());
	Video = Unigine::WidgetSpriteVideo::create(/*VGui->getGui(),*/ VideoFile);
	Video->setWidth(VGui->getScreenWidth());
	Video->setHeight(VGui->getScreenHeight());
	Video->setLoop(1);
	Video->play();

	// Add Sound with Video
	Sound = Unigine::static_ptr_cast<Unigine::SoundSource>(SoundNode.get());
	Sound->setSampleName(VideoFile);
	Sound->play();
	Video->setSoundSource(Sound);

	// Add Video to Object in World
	Unigine::GuiPtr VGUIP = VGui->getGui();
	VGUIP->addChild(Video, VGUIP->ALIGN_EXPAND | VGUIP->ALIGN_OVERLAP);

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Button, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Canvas, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Sprite, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
}

void Widgets::Update() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_U)) { 
		Angle = Unigine::Math::clamp(Angle - Unigine::Game::getIFps() * 36, 0.0f, 250.0f);
		RotateImage();
	}
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_I)) {
		Angle = Unigine::Math::clamp(Angle + Unigine::Game::getIFps() * 36, 0.0f, 250.0f);
		RotateImage();
	}
}

void Widgets::Shutdown() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Button)) GUI->removeChild(Button);
	if (GUI->isChild(Canvas)) GUI->removeChild(Canvas);
	if (GUI->isChild(Sprite)) GUI->removeChild(Sprite);

	if (Button) Button.deleteLater();
	if (Canvas) Canvas.deleteLater();
	if (Sprite) Sprite.deleteLater();
}

void Widgets::RotateImage() {
	
	// cos0 - sin0
	// cos0 + sin0
	// 0

	Unigine::Math::vec3 Piv{
		(Unigine::Math::cos(Angle * Unigine::Math::Consts::DEG2RAD) * -hSize) - (Unigine::Math::sin(Angle * Unigine::Math::Consts::DEG2RAD) * -hSize),
		(Unigine::Math::cos(Angle * Unigine::Math::Consts::DEG2RAD) * -hSize) + (Unigine::Math::sin(Angle * Unigine::Math::Consts::DEG2RAD) * -hSize),
		0
	};

	Unigine::Math::quat Rot{ 0.0f,0.0f, Angle };
	Unigine::Math::mat4 Mat{ Rot, Piv };
	Sprite->setLayerTransform(ImageFile.size(), Mat);
}