/*
Written by: Parranoia
*/

#include "ScriptPCH.h"

#define GM_LEVEL 1 //Change the 1 to whichever GM level you want to set the account to.

class vip : public ItemScript
{
	public:
		vip() : ItemScript("vip"){}

		bool OnUse(Player * player, Item * item, SpellCastTargets const& targets)
		{

			QueryResult account = CharacterDatabase.PQuery("SELECT * FROM characters WHERE guid = '%u'", player->GetGUID());
			Field * accID = account->Fetch();

			LoginDatabase.PExecute("REPLACE INTO account_access (id, gmlevel, RealmID) VALUES ('%u', '%u', -1)", accID[1].GetInt32(), GM_LEVEL);
			player->GetSession()->SendNotification("Your account has been upgraded!");


			return true;
		}

};

void AddSC_vip()
{
	new vip();
}