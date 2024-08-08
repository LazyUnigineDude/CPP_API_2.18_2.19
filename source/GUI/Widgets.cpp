#include "Widgets.h"
REGISTER_COMPONENT(Widgets);

void Widgets::Init() {

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

	Slider = Unigine::WidgetSlider::create(0, 100, 50);
	Slider->setOrientation(0);
	Slider->setPosition(200, 250);
	Slider->setButtonColor(Unigine::Math::vec4_blue);
	Slider->getEventChanged().connect(this, &Widgets::Changed);

	Canvas = Unigine::WidgetCanvas::create();
	Canvas->setPosition(400, 400);

	int Square = Canvas->addPolygon(0);
	Canvas->setPolygonColor(Square, Unigine::Math::vec4_green);
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3(   0, 200, 0));
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3(   0,   0, 0));
	Canvas->addPolygonPoint(Square, Unigine::Math::vec3( 200,   0, 0));
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

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Button, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Slider, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(Canvas, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
}

void Widgets::Shutdown() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Button)) GUI->removeChild(Button);
	if (GUI->isChild(Slider)) GUI->removeChild(Slider);
	if (GUI->isChild(Canvas)) GUI->removeChild(Canvas);

	if (Button) Button.deleteLater();
	if (Slider) Slider.deleteLater();
	if (Canvas) Canvas.deleteLater();
}
