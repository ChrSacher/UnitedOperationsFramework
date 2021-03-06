CFGFUNCFOLDER(HeadlessAI,check);
    CFGFUNC(AICheck,checkManualPos);
    CFGFUNC(AICheck,checkNearbyAll);
    CFGFUNC(AICheck,checkNearbyPlayer);
    CFGFUNC(AICheck,checkStance);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,common);
    CFGFUNC(AICommon,deleteVehicles);
    CFGFUNC(AICommon,enableZones);
    CFGFUNC(AICommon,removeKit);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,combat);
    CFGFUNC(AICombat,ArmEmptyStatic);
    CFGFUNC(AICombat,CombatAttack);
    CFGFUNC(AICombat,CombatDefend);
    CFGFUNC(AICombat,CombatMode);
    CFGFUNC(AICombat,CombatMoveTo);
    CFGFUNC(AICombat,CombatResponse);
    CFGFUNC(AICombat,DestroyBuilding);
    CFGFUNC(AICombat,FindCoverPos);
    CFGFUNC(AICombat,FlankManeuver);
    CFGFUNC(AICombat,FocusedAccuracy);
    CFGFUNC(AICombat,ForceHeal);
    CFGFUNC(AICombat,FormationChange);
    CFGFUNC(AICombat,FragmentMove);
    CFGFUNC(AICombat,LoiterAction);
    CFGFUNC(AICombat,MoveInCombat);
    CFGFUNC(AICombat,MoveToCover);
    CFGFUNC(AICombat,PlaceMine);
    CFGFUNC(AICombat,RadioCommsEnemy);
    CFGFUNC(AICombat,RearmGo);
    CFGFUNC(AICombat,RearmSelf);
    CFGFUNC(AICombat,ReGroup);
    CFGFUNC(AICombat,SightAid);
    CFGFUNC(AICombat,SuppressingShots);
    CFGFUNC(AICombat,ThrowGrenade);
    CFGFUNC(AICombat,WatchEnemy);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,create);
    CFGFUNC(AICreate,createFunctions);
    CFGFUNC(AICreate,createGroup);
    CFGFUNC(AICreate,createOccupyGroup);
    CFGFUNC(AICreate,createUnit);
    CFGFUNC(AICreate,createVehicle);
    CFGFUNC(AICreate,createWaypoint);
    CFGFUNC(AICreate,createWaypointModified);
    CFGFUNC(AICreate,createWaypoints);
    CFGFUNC(AICreate,createZone);
    CFGFUNC(AICreate,setupZone);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,dangercauses);
    CFGFUNC(AIDanger,CombatMovement);
    CFGFUNC(AIDanger,CurrentStance);
    CFGFUNC(AIDanger,DeadBodyDetection);
    CFGFUNC(AIDanger,ExplosionDetection);
    CFGFUNC(AIDanger,MoveToCoverGroup);
    CFGFUNC(AIDanger,RecentEnemyDetected);
    CFGFUNC(AIDanger,SetCombatStance);
    CFGFUNC(AIDanger,stopToShoot);
    CFGFUNC(AIDanger,VehicleHandleDanger);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,debug);
    CFGFUNC(AIDebug,debugSyncedModules);
    CFGFUNC(AIDebug,debugCreateMarker);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,Diag);
    CFGFUNC(AIDiag,AttachPosition);
    CFGFUNC(AIDiag,BuildingCheck);
    CFGFUNC(AIDiag,BuildingSpawnCheck);
    CFGFUNC(AIDiag,CheckStatic);
    CFGFUNC(AIDiag,Classvehicle);
    CFGFUNC(AIDiag,ClosestEnemy);
    CFGFUNC(AIDiag,ClosestObject);
    CFGFUNC(AIDiag,DriverCheck);
    CFGFUNC(AIDiag,EnemyArray);
    CFGFUNC(AIDiag,HasRadioGroup);
    CFGFUNC(AIDiag,IRCheck);
    CFGFUNC(AIDiag,LOSCheck);
    CFGFUNC(AIDiag,NearEnemies);
    CFGFUNC(AIDiag,searchNestedArray);
    CFGFUNC(AIDiag,StanceModifier);
    CFGFUNC(AIDiag,UnitCheck);
    CFGFUNC(AIDiag,Waypointcheck);
    CFGFUNC(AIDiag,WepSupCheck);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,Eventhandlers);
    CFGFUNC(AIEventHandlers,onAIHit);
    CFGFUNC(AIEventHandlers,playerInit);
    CFGFUNC(AIEventHandlers,onInit);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,get);
    CFGFUNC(AIGet,getBuildingList);
    CFGFUNC(AIGet,getBuildings);
    CFGFUNC(AIGet,getGroupVariables);
    CFGFUNC(AIGet,getNearestBuilding);
    CFGFUNC(AIGet,getNearestBuildings);
    CFGFUNC(AIGet,getNearestGroupBuildings);
    CFGFUNC(AIGet,getNewPos);
    CFGFUNC(AIGet,getRandomBuilding);
    CFGFUNC(AIGet,getRandomBuildings);
    CFGFUNC(AIGet,getRandomGroupBuildings);
    CFGFUNC(AIGet,getRandomPositionCircle);
    CFGFUNC(AIGet,getSide);
    CFGFUNC(AIGet,getStartBuilding);
    CFGFUNC(AIGet,getTasks);
    CFGFUNC(AIGet,getTaskParams);
    CFGFUNC(AIGet,getTurrets);
    CFGFUNC(AIGet,getWaypointDetails);
    CFGFUNC(AIGet,getVehicleRoles);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,GetInfo);
    CFGFUNC(AIGetInfo,getDetails);
    CFGFUNC(AIGetInfo,getDetailsArray);
    CFGFUNC(AIGetInfo,getDetailsGroup);
    CFGFUNC(AIGetInfo,getDetailsThing);
    CFGFUNC(AIGetInfo,getDetailsVehicle);
    CFGFUNC(AIGetInfo,getDetailsVehicleEmpty);
    CFGFUNC(AIGetInfo,getDetailsUnit);
    CFGFUNC(AIGetInfo,getSynced);
    CFGFUNC(AIGetInfo,getSyncedGroups);
    CFGFUNC(AIGetInfo,getSyncedModules);
    CFGFUNC(AIGetInfo,getSyncedObjects);
    CFGFUNC(AIGetInfo,getSyncedObjectsTemplate);
    CFGFUNC(AIGetInfo,getSyncedRespawns);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,Main);
    CFGFUNC(AIMain,ActiveHandler);
    CFGFUNC(AIMain,GroupHandler);
    CFGFUNC(AIMain,MapMarkers);
    CFGFUNC(AIMain,initMain);
    CFGFUNC(AIMain,zoneMonitor);
    CFGFUNC(AIMain,QueueHandle);
    class checkifHC { scope = 1;CFGFUNCFOLDEREND;
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,modules);
    CFGFUNC(AIModules,control);
    CFGFUNC(AIModules,module);
    CFGFUNC(AIModules,position);
    CFGFUNC(AIModules,respawn);
    CFGFUNC(AIModules,task);
    CFGFUNC(AIModules,temp);
    CFGFUNC(AIModules,zone);
    CFGFUNC(AIModules,enablezone);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,set);
    CFGFUNC(AISet,setAssignedVehicle);
    CFGFUNC(AISet,setBuildingPos);
    CFGFUNC(AISet,setCompletedTasks);
    CFGFUNC(AISet,setFlashlights);
    CFGFUNC(AISet,setGroupBehaviour);
    CFGFUNC(AISet,setGroupVariables);
    CFGFUNC(AISet,setMarkerPos);
    CFGFUNC(AISet,setMultiOccupy);
    CFGFUNC(AISet,setPersistent);
    CFGFUNC(AISet,setRadial);
    CFGFUNC(AISet,setRespawn);
    CFGFUNC(AISet,setStance);
    CFGFUNC(AISet,setSurrender);
    CFGFUNC(AISet,setTracker);
    CFGFUNC(AISet,setVehicle);
    CFGFUNC(AISet,setZone);
CFGFUNCFOLDEREND;

CFGFUNCFOLDER(HeadlessAI,task);
    CFGFUNC(AITask,taskActivate);
    CFGFUNC(AITask,taskAssign);
    CFGFUNC(AITask,taskCheck);
    CFGFUNC(AITask,taskComplete);
    CFGFUNC(AITask,taskForceFire);
    CFGFUNC(AITask,taskForceHold);
    CFGFUNC(AITask,taskGroup);
    CFGFUNC(AITask,taskLoiter);
    CFGFUNC(AITask,taskHoldUntil);
    CFGFUNC(AITask,taskInit);
    CFGFUNC(AITask,taskBuildingPatrol);
    CFGFUNC(AITask,taskBuildingDefend);
    CFGFUNC(AITask,taskMonitor);
    CFGFUNC(AITask,taskMoveBuilding);
    CFGFUNC(AITask,taskMoveBuildings);
    CFGFUNC(AITask,taskMoveGroupBuildingsDefend);
    CFGFUNC(AITask,taskMoveGroupBuildingsPatrol);
    CFGFUNC(AITask,taskMoveMultipleBuildingsDefend);
    CFGFUNC(AITask,taskMoveMultipleBuildingsPatrol);
    CFGFUNC(AITask,taskMoveNearestBuildingDefend);
    CFGFUNC(AITask,taskMoveNearestBuildingPatrol);
    CFGFUNC(AITask,taskMoveRandomBuildingDefend);
    CFGFUNC(AITask,taskMoveRandomBuildingPatrol);
    CFGFUNC(AITask,taskMoveRandomGroupBuildingsDefend);
    CFGFUNC(AITask,taskMoveRandomGroupBuildingsPatrol);
    CFGFUNC(AITask,taskMoveRandomMultipleBuildingsDefend);
    CFGFUNC(AITask,taskMoveRandomMultipleBuildingsPatrol);
    CFGFUNC(AITask,taskRegister);
    CFGFUNC(AITask,taskRemoveZoneActivated);
    CFGFUNC(AITask,taskSearchNearby);
    CFGFUNC(AITask,taskSet);
    CFGFUNC(AITask,taskSetBunker);
    CFGFUNC(AITask,taskSentry);
    CFGFUNC(AITask,taskPlacement);
    CFGFUNC(AITask,taskPatrol);
    CFGFUNC(AITask,taskPatrolPerimeter);
CFGFUNCFOLDEREND;
