unit CBNAMES;

interface

const
   ncb_initLib           = '_acd_inl@12';
   ncb_initLibDirect     = '_acd_ild@4';
   ncb_doneLib           = '_acd_dol@0';
   ncb_getLibVersion     = '_acd_glv@12';
   ncb_getCurrentUser    = '_acd_gcu@8';
   ncb_getLibSettings    = '_acd_gls@4';
   ncb_createArchive     = '_acd_cra@24';
   ncb_getArchiveInfo    = '_acd_gai@16';
   ncb_openArchive       = '_acd_opa@16';
   ncb_getFirstFile      = '_acd_gff@8';
   ncb_getNextFile       = '_acd_gnf@8';
   ncb_addFile           = '_acd_adf@24';
   ncb_extractCurFile    = '_acd_ecf@20';
   ncb_closeArchive      = '_acd_cla@12';
   ncb_abortArchive      = '_acd_aba@4';
   ncb_testFileKPD       = '_acd_tfs@12';
   ncb_setFileKPD        = '_acd_sfs@12';
   ncb_delFileKPD        = '_acd_dfs@8';
   ncb_getFileKPDCount   = '_acd_gfsc@4';
   ncb_dbOpenDatabase    = '_acd_odb@12';
   ncb_dbCloseDatabase   = '_acd_cdb@4';
   ncb_dbPackDatabase    = '_acd_pdb@4';
   ncb_dbGetDBHandles    = '_acd_gdh@8';
   ncb_dbGetDatabaseInfo = '_acd_gdi@8';
   ncb_dbDeleteSI        = '_acd_dpk@8';
   ncb_dbAddSI           = '_acd_apk@16';
   ncb_dbExtractSI       = '_acd_epk@12';
   ncb_enumSI            = '_acd_enk@16';
   ncb_dbGetSIDetails    = '_acd_gpd@16';
   ncb_createIA          = '_acd_crk@12';
   ncb_getPIAInfo        = '_acd_gsi@8';
   ncb_changePIAPassword = '_acd_csp@12';
   ncb_dropSICaches      = '_acd_dpc@0';
   ncb_createMemoryFile  = '_acd_crmf@20';
   ncb_getMemoryFileInfo = '_acd_gmfi@16';
   ncb_setMemoryFileSize = '_acd_smfs@8';
   ncb_closeMemoryFile   = '_acd_clmf@4';
   ncb_createSession     = '_acd_crs@0';
   ncb_linkSession       = '_acd_lis@4' ;
   ncb_unlinkSession     = '_acd_uns@0' ;
   ncb_freeSession       = '_acd_frs@4' ;
   ncb_getErrorInfo      = '_acd_gei@4' ;
   ncb_getErrorString    = '_acd_ges@12' ;
   ncb_addLogStrings     = '_acd_als@12' ;

implementation

end.
