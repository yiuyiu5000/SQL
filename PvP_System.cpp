#include "ScriptPCH.h"
 
class System_OnKill : public PlayerScript
{
        public:
                System_OnKill() : PlayerScript("System_OnKill") {}
 
        void OnPVPKill(Player * Killer, Player * Victim)
        {
                uint64 KillerGUID = Killer->GetGUID();
                uint64 VictimGUID = Victim->GetGUID();
 
                struct KillStreak_Info
                {
                        uint32 killstreak;
                        uint64 lastkill;
                };
 
                static std::map<uint64, KillStreak_Info> KillStreakData;
 
                if( KillerGUID == VictimGUID || KillStreakData[KillerGUID].lastkill == VictimGUID )
                        return;
 
                KillStreakData[KillerGUID].killstreak++;
                KillStreakData[KillerGUID].lastkill = VictimGUID;
                KillStreakData[VictimGUID].killstreak = 0;
                KillStreakData[VictimGUID].lastkill = 0;
 
                switch( KillStreakData[KillerGUID].killstreak )
                {
                        char msg[250];
                        case 3:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 3);
                                break;
 
                        case 5:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 5);
                                break;
 
                        case 8:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 8);
                                break;
 
                        case 10:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 10);
                                break;
 
                        case 15:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 15);
                                break;
 
                        case 20:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 20);
                                break;
 
                        case 30:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 30);
                                break;
 
                        case 40:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 40);
                                break;
 
                        case 50:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 50);
                                break;
 
                        case 100:
                                snprintf(msg, 250, "[PvP System]: %s is on a killstreak of %u!!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
								sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
								Killer->AddItem(29434, 100);
                                break;
                }
        }
};
 
void AddSC_PvP_System()
{
    new System_OnKill;
}