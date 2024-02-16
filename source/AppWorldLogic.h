#ifndef __APP_WORLD_LOGIC_H__
#define __APP_WORLD_LOGIC_H__

#include <UnigineLogic.h>
#include <UnigineStreams.h>

class AppWorldLogic : public Unigine::WorldLogic
{

public:
	AppWorldLogic();
	~AppWorldLogic() override;

	int init() override;

	int update() override;
	int postUpdate() override;
	int updatePhysics() override;

	int shutdown() override;

	int save(const Unigine::StreamPtr &stream) override;
	int restore(const Unigine::StreamPtr &stream) override;
};

#endif // __APP_WORLD_LOGIC_H__
