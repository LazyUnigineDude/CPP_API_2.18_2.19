#pragma once
#include <Unigine.h>

struct RandomStruct : public Unigine::ComponentStruct {

	PROP_PARAM(Int, ID, 0, "ID Value", "ID of the Current Object");
	PROP_PARAM(String, Name, " ", "Name", "Name of the Account Holder");
	PROP_PARAM(Float, Amount, 0, "Debit", "Amount in Dollars");
};

class ComponentCheck : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(ComponentCheck, ComponentBase);
		COMPONENT_INIT(Init);
		COMPONENT_UPDATE_ASYNC_THREAD(UpdateAsync);
		COMPONENT_UPDATE_SYNC_THREAD(UpdateSync);
		COMPONENT_UPDATE(Update);
		COMPONENT_POST_UPDATE(UpdatePost);
		COMPONENT_UPDATE_PHYSICS(UpdatePhysics);
		COMPONENT_SWAP(Swap);
		COMPONENT_SHUTDOWN(Shutdown);

		//		   Type, Name,  Val, Name in prop, Tooltip,				  Group
		PROP_PARAM(Int,  IDNum,  3,  "ID"        , "It is the Barcode ID", "Ingredient");
		PROP_PARAM(Float, FreshAmount, 30.0f, "Freshness", "It is the Freshness Value", "Ingredient");
		PROP_PARAM(Switch, Item, 2, "Onion, Tomato, Celery", "IList", "An Ingredient that we chose from a list", "Ingredient");
		PROP_PARAM(Toggle, IsFresh, 0, "Is it Fresh?", "Check if the Value is Above 50", "Ingredient");
		
		PROP_PARAM(Double, ID, 999999, "ID", "RandomIDinDoubleDigits", "Advanced");
		PROP_PARAM(String, Name, " ", "Name of Thing", "Write the name of the object with that ID", "Advanced");
		PROP_PARAM(Vec3, MinMax, "Floats", "Medium Value 3 PART", "Advanced");
		PROP_PARAM(DVec3, DMinMax, "Decimals", "High Value 3 PART", "Advanced");
		PROP_PARAM(IVec3, IMinMax, "Integers", "Integer Value 3 PART", "Advanced");
		PROP_ARRAY(Int, ListData, "List Of Nums", "How to Create a List inside the Editor", "Advanced");

		PROP_PARAM(Mask, MaskVal, 0, "Mask Value", "Mask Check Value For xxx", "Editor Specific");
		PROP_PARAM(Color, Col, "Color Value", "Choose a random Color", "Editor Specific");
		PROP_PARAM(File, Data, 0, "File Asset", "Drag an Asset from the AssetBrowser and add it here", "Editor Specific");
		PROP_PARAM(Material, Mat, "Default Material", "Drag a Material from the AssetBrowser and add it here", "Editor Specific");
		PROP_PARAM(Node, NodeItem, "Default Node", "Drag an Object in World to here", "Editor Specific");

		PROP_STRUCT(RandomStruct, BaseID, "Admin", "Setup Main Administrator For Account", "Struct");
		PROP_ARRAY_STRUCT(RandomStruct, OtherID, "Users", "Setup Other Users in Account", "Struct");

protected:
	void Init();
	void Update();
};

