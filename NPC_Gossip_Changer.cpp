#include "ScriptPCH.h"


//BE SURE TO CHANGE THE GOSSIP OPTIONS FURTHER DOWN
enum defines
{
	TOKEN_ID = 20558,
	RACE_CHANGE_TOKENS_REQUIRED = 7,
	FACTION_CHANGE_TOKENS_REQUIRED = 10,
	NAME_CHANGE_TOKENS_REQUIRED = 7,

};

class NPC_Gossip_Changer : public CreatureScript
{
	public:
		NPC_Gossip_Changer() : CreatureScript("NPC_Gossip_Changer"){}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			pPlayer->ADD_GOSSIP_ITEM(4, "[7 Tokens] Change my race", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "[10 Tokens] Change my faction", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "[7 Tokens] Change my name", GOSSIP_SENDER_MAIN, 2);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;

			WorldSession * m_session = Player->GetSession();

			switch(uiAction)
			{
				case 0:
					if(Player->HasItemCount(TOKEN_ID, RACE_CHANGE_TOKENS_REQUIRED))
					{
						Player->DestroyItemCount(TOKEN_ID, RACE_CHANGE_TOKENS_REQUIRED, true, false);
						Player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
						CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '128' WHERE guid = %u", (Player->GetGUID()));
						m_session->SendNotification("Relog. You will be prompted on your next login.");
						Player->PlayerTalkClass->SendCloseGossip();

					}
					else
					{
						m_session->SendNotification("You don't have enough vote tokens");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					break;
				case 1:
					if(Player->HasItemCount(TOKEN_ID, FACTION_CHANGE_TOKENS_REQUIRED))
					{
						Player->DestroyItemCount(TOKEN_ID, FACTION_CHANGE_TOKENS_REQUIRED, true, false);
						Player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
						CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", (Player->GetGUID()));
						m_session->SendNotification("Relog. You will be prompted on your next login.");
						Player->PlayerTalkClass->SendCloseGossip();

					}
					else
					{
						m_session->SendNotification("You don't have enough vote tokens");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					break;
				case 2:
					if(Player->HasItemCount(TOKEN_ID, NAME_CHANGE_TOKENS_REQUIRED))
					{
						Player->DestroyItemCount(TOKEN_ID, NAME_CHANGE_TOKENS_REQUIRED, true, false);
						Player->SetAtLoginFlag(AT_LOGIN_RENAME);
						CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '1' WHERE guid = %u", (Player->GetGUID()));
						m_session->SendNotification("Relog. You will be prompted on your next login.");
						Player->PlayerTalkClass->SendCloseGossip();

					}
					else
					{
						m_session->SendNotification("You don't have enough vote tokens");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					break;

			}
			return true;
		}

};

void AddSC_NPC_Gossip_Changer()
{
	new NPC_Gossip_Changer();
}
