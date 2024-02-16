#ifndef __APP_EDITOR_LOGIC_H__
#define __APP_EDITOR_LOGIC_H__

#include <UnigineLogic.h>

class AppEditorLogic : public Unigine::EditorLogic
{
public:
	AppEditorLogic();
	~AppEditorLogic() override;

	int init() override;

	int update() override;
	int render(const Unigine::EngineWindowViewportPtr &window) override;

	int shutdown() override;

	int worldInit() override;
	int worldShutdown() override;
	int worldSave() override;
};

#endif // __APP_EDITOR_LOGIC_H__
