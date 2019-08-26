////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Sacher, v1.063, #Dyroxu)
////////////////////////////////////////////////////////
#include "\x\UO_FW\addons\Main\script_macros.hpp"
#define MEANCALCULATIONTIME 30
#define MEANAIMTIME 20
#define MEANSPOTTINGACCURACY 300
#define MEANPlOTTEDACCURACY 50
#define MAXSPOTTINGROUNDS 3
#define MEANFIRERATE 1
#define SPOTTINGROUNDSREQUIRED true
#define OBSACCURACY 100
#define OBSSPEED 30

#define MILSPERROUND  6400
/*
#define QEGVAR(Firemission,ArtIsFiring) "SARTisInAFiremission"
#define QEGVAR(Firemission,ArtFireRate) "SArtFireRate"
#define QEGVAR(Firemission,ArtAccuracy) "SArtAccuracy"
#define QEGVAR(Firemission,ArtSpotAccuracy) "SArtSpottingAccuracy"
#define QEGVAR(Firemission,ArtAimSpeed) "SArtAimSpeed"
#define QEGVAR(Firemission,ArtCalcSpeed) "SArtCalcSpeed"
#define QEGVAR(Firemission,ArtCustomName) "SArtCustomName"
#define QEGVAR(Firemission,ArtUnlimitedAmmo) "SArtUnlimitedAmmo"
#define QEGVAR(Firemission,ArtHasEH) "SArtHasEventHandler"
#define QEGVAR(Firemission,ArtFMText) "SArtyFiremissionText"
#define QEGVAR(Firemission,ArtRoundsFired) "SArtFiremissionRoundsFired"
#define QEGVAR(Firemission,ArtHandle) "SArtFiremissionHandle"
#define QEGVAR(Firemission,ArtCaller) "SArtCaller"
#define QEGVAR(Firemission,ArtReady) "SArtReady"


#define QEGVAR(Firemission,ObsAccuracy) "SObserverAccuracy"
#define QEGVAR(Firemission,ObsSpeed) "SObserverSpeed"

#define QEGVAR(Firemission,ObsGuns) "SPlayerArtilleryGuns"
#define QEGVAR(Firemission,PlayerReceived) "SPlayerReceived"
#define QEGVAR(Firemission,PlayerAceOpions) "SPlayerAceOptions"
*/



#define COMPONENT Firemission

#define ARTIWIDTHMainSPACE  0.25
#define ARTIHEIGHTMainSPACE  0.15
#define ARTILAYOUTHEIGHT   0.05
#define ARTILAYOUTHEIGHTSPACE   0.055
#define ARTIBORDERTHICKNESS   0.01
#define ARTILAYOUTWIDTH   0.15
#define ARTILAYOUTWIDTHSPACE   0.16

#define PFM_DIA_IDD_DISPLAY 765
#define PFM_DIA_IDC_GUNSELECT 29345
#define PFM_DIA_IDC_SHELLSELECT 29346
#define PFM_DIA_IDC_GRID 29347
#define PFM_DIA_IDC_DISPERSION 29348
#define PFM_DIA_IDC_BURSTNUMBER 29349
#define PFM_DIA_IDC_BURSTROUNDS 29350
#define PFM_DIA_IDC_BURSTDELAY 29351
#define PFM_DIA_IDC_SPOTTING 29352

#define LFM_DIA_IDD_DISPLAY 766
#define LFM_DIA_IDC_GUNSELECT 29353
#define LFM_DIA_IDC_SHELLSELECT 29354
#define LFM_DIA_IDC_STARTGRID 29355
#define LFM_DIA_IDC_ENDGRID 29356
#define LFM_DIA_IDC_BURSTNUMBER 29357
#define LFM_DIA_IDC_BURSTROUNDS 29358
#define LFM_DIA_IDC_BURSTDELAY 29359
#define LFM_DIA_IDC_SPOTTING 29360

#define BFM_DIA_IDD_DISPLAY 767
#define BFM_DIA_IDC_GUNSELECT 29361
#define BFM_DIA_IDC_SHELLSELECT 29362
#define BFM_DIA_IDC_STARTGRID 29363
#define BFM_DIA_IDC_ENDGRID 29364
#define BFM_DIA_IDC_BURSTNUMBER 29365
#define BFM_DIA_IDC_BURSTROUNDS 29366
#define BFM_DIA_IDC_BURSTDELAY  29367
#define BFM_DIA_IDC_SPOTTING  29368

#define DFM_DIA_IDD_DISPLAY 768
#define DFM_DIA_IDC_GUNSELECT 29369
#define DFM_DIA_IDC_SHELLSELECT 29370
#define DFM_DIA_IDC_GRID 29371
#define DFM_DIA_IDC_INNERRADIUS 29372
#define DFM_DIA_IDC_OUTERRADIUS 29373
#define DFM_DIA_IDC_BURSTNUMBER 29374
#define DFM_DIA_IDC_BURSTROUNDS 29375
#define DFM_DIA_IDC_BURSTDELAY  29376
#define DFM_DIA_IDC_SPOTTING  29377

#define MFM_DIA_IDD_DISPLAY 769
#define MFM_DIA_IDC_GUNSELECT 29378
#define MFM_DIA_IDC_SHELLSELECT 29379
#define MFM_DIA_IDC_NAME 29380
#define MFM_DIA_IDC_DISPERSION 29381
#define MFM_DIA_IDC_BURSTNUMBER 29383
#define MFM_DIA_IDC_BURSTROUNDS 29384
#define MFM_DIA_IDC_BURSTDELAY  29385
#define MFM_DIA_IDC_SPOTTING  29386

#define GSFM_DIA_IDD_DISPLAY 770
#define GSFM_DIA_IDC_GUNSELECT 29387
#define GSFM_DIA_IDC_SHELLSELECT 29388
#define GSFM_DIA_IDC_GRID 29389

#define PSFM_DIA_IDD_DISPLAY 771
#define PSFM_DIA_IDC_GUNSELECT 29390
#define PSFM_DIA_IDC_SHELLSELECT 29391
#define PSFM_DIA_IDC_GRID 29392
#define PSFM_DIA_IDC_MILS 29393
#define PSFM_DIA_IDC_DISTANCE 29394

#define POFM_DIA_IDD_DISPLAY 772
#define POFM_DIA_IDC_GUNSELECT 29395
#define POFM_DIA_IDC_SHELLSELECT 29396
#define POFM_DIA_IDC_GRID 29397
#define POFM_DIA_IDC_MILS 29398
#define POFM_DIA_IDC_DISTANCE 29399
#define POFM_DIA_IDC_DISPERSION 29400
#define POFM_DIA_IDC_BURSTNUMBER 29401
#define POFM_DIA_IDC_BURSTROUNDS 29402
#define POFM_DIA_IDC_BURSTDELAY 29403
#define POFM_DIA_IDC_SPOTTING 29405


#define GUIDE_DIA_IDD_DISPLAY 773
#define GUIDE_STRING = "Selected gun: Gun which will fire the shells. When clicking on the gun it will show its ammunition inside the Aviable ammuntion combo box.\
                Aviable Ammuntion: Ammuntion the currently selected gun holds. Make sure the right one is selected.\
                Grid: Grid where the artillery shall hit. Must be a 4,6 or 8-Digit Grid\
                Dispersion: Radius of the firemission in meters\
                Number of Salvos: How many salvos are fired. Every Salvos decides the position where it will land.\
                Rounds per Salvo: A Salvo will selected a Position(by magic) inside the grid with Dispersion and then fire n rounds onto that position.\
                Delay between salvos: A Delay between every salvo in seconds. Min Rate of fire of gun * number of a rounds per salvo. Min is calcualted by the script. Motars are 6sec per round.\
                Min Spotting round distance: Distance for when the spotting rounds will end. If they are closer to grid than Dispersion the actuall fire mission will start. It gives time for aborting the mission\
                and adding some realism to it. Put 9999 to not fire spotting rounds but might make actuall firemision innacurate.\
\
                Firemission Information: Will display information about the current firemission of a gun. Will only be aviable mid firemission.\
                Stop firemission: Stops a firemission.\
\
                Point firemission: Point target firemission. Will fire onto a Circle with Grid as Center.\
                Donut firemission. Will fire onto the Space between 2 Circles.\
                Line  firemission: Firemission will move from start to finish in intervalls. Salvos define intervalls.\
                Marker firemission: Will fire a point target firemission onto a Marker with Text.\
                Polar firemission: Requires your location as grid and mils and distance and will call a point firemission."
