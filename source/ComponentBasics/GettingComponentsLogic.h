#include <Unigine.h>
#include "../Movements/Movement.h"

struct GettingComponentsLogic : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(GettingComponentsLogic, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);

	PROP_PARAM(Node, NodeItem);

protected:
	void Init(), Update();
	ChessMovement* _Movement;
};
