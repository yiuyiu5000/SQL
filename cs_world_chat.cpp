    #include "ScriptPCH.h"
    #include "Chat.h"
     
    class cs_world_chat : public CommandScript
    {
            public:
                    cs_world_chat() : CommandScript("cs_world_chat"){}
     
            ChatCommand * GetCommands() const
            {
                    static ChatCommand WorldChatCommandTable[] =
                    {
                            {"chat",        SEC_PLAYER,             true,           &HandleWorldChatCommand,        "", NULL},
                            {NULL,          0,                              false,          NULL,                                           "", NULL}
                    };
     
                    return WorldChatCommandTable;
            }
     
            static bool HandleWorldChatCommand(ChatHandler * handler, const char * args)
            {
                    if (!args)
                            return false;
     
                    std::string msg = "";
                    Player * player = handler->GetSession()->GetPlayer();
     
                    switch(player->GetSession()->GetSecurity())
                    {

							// Player 0
							case SEC_PLAYER:
                            msg += "|cffff0000[Twink Chat] |cffffffff[";
                            msg += player->GetName();
                            msg += "] |cfffaeb00";
                            break;
							// VIP 1
                            case SEC_VIP:
                                    msg += "|cff00ffff[VIP] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
							// VIP+ 2
                            case SEC_VIPPLUS:
                                    msg += "|cffff00ff[VIP+] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // TrialGm 3
                            case SEC_TRIALGM:
                                    msg += "|cff8a28be[Trial GM] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
							// Moderator 4
                            case SEC_MODERATOR:
                                    msg += "|cffff7f50[Mod] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
									
                            // GM 5
                            case SEC_GAMEMASTER:
                                    msg += "|cffe9967a[GM] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // Trial Dev 6
                            case SEC_TRIALDEV:
                                    msg += "|cffdc143c[Trial Dev] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // Trial Admin 7
                            case SEC_TRIALADMIN:
                                    msg += "|cff8fbc8b[Trial Admin] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // HEAD GM 8
                            case SEC_HEADGM:
                                    msg += "|cff808080[Head GM] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // Senior ADMIN 9
                            case SEC_ADMIN:
                                    msg += "|cff1e90ff[Admin] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // dev 10
                            case SEC_DEV:
                                    msg += "|cffcd5c5c[Dev] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // Senior Admin 11
                            case SEC_SENIORADMIN:
                                    msg += "|cff7cfc00[Senior Admin] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // SeniorDev 12
                            case SEC_SENIORDEV:
                                    msg += "|cff800080[Senior Dev] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
                            // HeadAdmin 13
                            case SEC_HEADADMIN:
                                    msg += "|cFFFFC0CB[Head Admin] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;									
                            // COREDEV 14
                            case SEC_COREDEV:
                                    msg += "|cFFFFC0CB[Core Dev] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
									
							// HEADDEV 15
							case SEC_HEADDEV:
                                    msg += "|cFFFFC0CB[Head Dev] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
							// Founder
							case SEC_ADMINISTRATOR:
                                    msg += "|cffc0c0c0[Founder] |cffffffff[";
                                    msg += player->GetName();
                                    msg += "] |cfffaeb00";
                                    break;
     
                    }
                           
                    msg += args;
                    sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);  
     
                    return true;
            }
    };
     
    void AddSC_cs_world_chat()
    {
            new cs_world_chat();
    }
