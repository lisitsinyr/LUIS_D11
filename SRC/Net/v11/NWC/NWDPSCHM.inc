(*
//ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
//บ (c) 1996-1997 Novell, Inc.  All rights reserved.                         บ
//บ                                                                          บ
//บ THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND        บ
//บ TREATIES.                                                                บ
//บ                                                                          บ
//บ NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,          บ
//บ DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         บ
//บ EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED    บ
//บ WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        บ
//บ                                                                          บ
//บ ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT บ
//บ THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.                         บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Source module name: NWDPSCHM.H                                           บ
//ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน
//บ Library VeRsIoN=1.0.0                                                    บ
//ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*)

(* Inclusion Control *)

{$IFNDEF  NWDPSCHM_H }
    {$DEFINE NWDPSCHM_H}
    (* Manifest Constant Definitions *)
    (*
// Values are for the new Attribute types and Classes that are added to the
// NDS schema for NetWare Distributed Print Services functionality.
*)
    {$DEFINE ROLE_EXPLANATION}
    Const ROLE_EXPLANATION = 'any trustee of this attribute';
    {$DEFINE LROLE_EXPLANATION}
    Const LROLE_EXPLANATION = 'a\0n\0y\0 \0t\0r\0u\0s\0t\0e\0e\0 \0o\0f\0 \0t\0h\0i\0s\0 \0a\0t\0t\0r\0i\0b\0u\0t\0e\0\0';
    {$DEFINE A_NDPS_OPERATOR_ROLE}
    Const A_NDPS_OPERATOR_ROLE = 'NDPS Operator Role';
    {$DEFINE LA_NDPS_OPERATOR_ROLE}
    Const LA_NDPS_OPERATOR_ROLE = 'N\0D\0P\0S\0 \0O\0p\0e\0r\0a\0t\0o\0r\0 \0R\0o\0l\0e\0\0';
    {$DEFINE A_NDPS_USER_ROLE}
    Const A_NDPS_USER_ROLE = 'NDPS User Role';
    {$DEFINE LA_NDPS_USER_ROLE}
    Const LA_NDPS_USER_ROLE = 'N\0D\0P\0S\0 \0U\0s\0e\0r\0 \0R\0o\0l\0e\0\0';
    (*
// NDPS Printer Object Attributes
*)
    {$DEFINE A_CLIENT_INSTALL_CANDIDATE}
    Const A_CLIENT_INSTALL_CANDIDATE = 'Client Install Candidate';
    {$DEFINE LA_CLIENT_INSTALL_CANDIDATE}
    Const LA_CLIENT_INSTALL_CANDIDATE = 'C\0l\0i\0e\0n\0t\0 \0I\0n\0s\0t\0a\0l\0l\0 \0C\0a\0n\0d\0i\0d\0a\0t\0e\0\0';
    {$DEFINE A_COLOR_SUPPORTED}
    Const A_COLOR_SUPPORTED = 'Color Supported';
    {$DEFINE LA_COLOR_SUPPORTED}
    Const LA_COLOR_SUPPORTED = 'C\0o\0l\0o\0r\0 \0S\0u\0p\0p\0o\0r\0t\0e\0d\0\0';
    {$DEFINE A_PDLS_SUPPORTED}
    Const A_PDLS_SUPPORTED = 'Page Description Languages';
    {$DEFINE LA_PDLS_SUPPORTED}
    Const LA_PDLS_SUPPORTED = 'P\0a\0g\0e\0 \0D\0e\0s\0c\0r\0i\0p\0t\0i\0o\0n\0 \0L\0a\0n\0g\0u\0a\0g\0e\0s\0\0';
    {$DEFINE A_NDPS_JOB_CONFIGURATIONS}
    Const A_NDPS_JOB_CONFIGURATIONS = 'NDPS Job Configurations';
    {$DEFINE LA_NDPS_JOB_CONFIGURATIONS}
    Const LA_NDPS_JOB_CONFIGURATIONS = 'N\0D\0P\0S\0 \0J\0o\0b\0 \0C\0o\0n\0f\0i\0g\0u\0r\0a\0t\0i\0o\0n\0s\0\0';
    {$DEFINE A_MAXIMUM_SPEED}
    Const A_MAXIMUM_SPEED = 'Maximum Speed';
    {$DEFINE LA_MAXIMUM_SPEED}
    Const LA_MAXIMUM_SPEED = 'M\0a\0x\0i\0m\0u\0m\0 \0S\0p\0e\0e\0d\0\0';
    {$DEFINE A_PRIMARY_NOTIFICATION_SERVICE}
    Const A_PRIMARY_NOTIFICATION_SERVICE = 'Primary Notification Service';
    {$DEFINE LA_PRIMARY_NOTIFICATION_SERVICE}
    Const LA_PRIMARY_NOTIFICATION_SERVICE = 'P\0r\0i\0m\0a\0r\0y\0 \0N\0o\0t\0i\0f\0i\0c\0a\0t\0i\0o\0n\0 \0S\0e\0r\0v\0i\0c\0e\0\0';
    {$DEFINE A_PRINTER_MECHANISM_TYPES}
    Const A_PRINTER_MECHANISM_TYPES = 'Printer Mechanism Types';
    {$DEFINE LA_PRINTER_MECHANISM_TYPES}
    Const LA_PRINTER_MECHANISM_TYPES = 'P\0r\0i\0n\0t\0e\0r\0 \0M\0e\0c\0h\0a\0n\0i\0s\0m\0 \0T\0y\0p\0e\0s\0\0';
    {$DEFINE A_PRINTER_STATUS}
    Const A_PRINTER_STATUS = 'Printer Status';
    {$DEFINE LA_PRINTER_STATUS}
    Const LA_PRINTER_STATUS = 'P\0r\0i\0n\0t\0e\0r\0 \0S\0t\0a\0t\0u\0s\0\0';
    {$DEFINE A_RESOLUTION}
    Const A_RESOLUTION = 'Resolution';
    {$DEFINE LA_RESOLUTION}
    Const LA_RESOLUTION = 'R\0e\0s\0o\0l\0u\0t\0i\0o\0n\0\0';
    {$DEFINE A_MAXIMUM_SPEED_UNITS}
    Const A_MAXIMUM_SPEED_UNITS = 'Maximum Speed Units';
    {$DEFINE LA_MAXIMUM_SPEED_UNITS}
    Const LA_MAXIMUM_SPEED_UNITS = 'M\0a\0x\0i\0m\0u\0m\0 \0S\0p\0e\0e\0d\0 \0U\0n\0i\0t\0s\0\0';
    {$DEFINE A_NOTIFICATION_PROFILE}
    Const A_NOTIFICATION_PROFILE = 'Notification Profile';
    {$DEFINE LA_NOTIFICATION_PROFILE}
    Const LA_NOTIFICATION_PROFILE = 'N\0o\0t\0i\0f\0i\0c\0a\0t\0i\0o\0n\0 \0P\0r\0o\0f\0i\0l\0e\0\0';
    {$DEFINE A_NOTIFICATION_CONSUMERS}
    Const A_NOTIFICATION_CONSUMERS = 'Notification Consumers';
    {$DEFINE LA_NOTIFICATION_CONSUMERS}
    Const LA_NOTIFICATION_CONSUMERS = 'N\0o\0t\0i\0f\0i\0c\0a\0t\0i\0o\0n\0 \0C\0o\0n\0s\0u\0m\0e\0r\0s\0\0';
    {$DEFINE A_PRIMARY_RESOURCE_SERVICE}
    Const A_PRIMARY_RESOURCE_SERVICE = 'Primary Resource Service';
    {$DEFINE LA_PRIMARY_RESOURCE_SERVICE}
    Const LA_PRIMARY_RESOURCE_SERVICE = 'P\0r\0i\0m\0a\0r\0y\0 \0R\0e\0s\0o\0u\0r\0c\0e\0 \0S\0e\0r\0v\0i\0c\0e\0\0';
    {$IFDEF IGNORE_THIS_CODE}
    {$ENDIF}
    {$DEFINE A_PSM_OBJECT_NAME}
    Const A_PSM_OBJECT_NAME = 'PSM Name';
    {$DEFINE LA_PSM_OBJECT_NAME}
    Const LA_PSM_OBJECT_NAME = 'P\0S\0M\0 \0N\0a\0m\0e\0\0';
    {$DEFINE A_PRINTER_AGENT_NAME}
    Const A_PRINTER_AGENT_NAME = 'Printer Agent Name';
    {$DEFINE LA_PRINTER_AGENT_NAME}
    Const LA_PRINTER_AGENT_NAME = 'P\0r\0i\0n\0t\0e\0r\0 \0A\0g\0e\0n\0t\0 \0N\0a\0m\0e\0\0';
    {$DEFINE A_PRINTER_QUEUE_LIST}
    Const A_PRINTER_QUEUE_LIST = 'NDPS Printer Queue List';
    {$DEFINE LA_PRINTER_QUEUE_LIST}
    Const LA_PRINTER_QUEUE_LIST = 'N\0D\0P\0S\0 \0P\0r\0i\0n\0t\0e\0r\0 \0Q\0u\0e\0u\0e\0 \0L\0i\0s\0t\0\0';
    {$DEFINE A_NDPS_DEFAULT_PRINTER}
    Const A_NDPS_DEFAULT_PRINTER = 'NDPS Default Printer';
    {$DEFINE LA_NDPS_DEFAULT_PRINTER}
    Const LA_NDPS_DEFAULT_PRINTER = 'N\0D\0P\0S\0 \0D\0e\0f\0a\0u\0l\0t\0 \0P\0r\0i\0n\0t\0e\0r\0\0';
    {$DEFINE A_DATAPOOL_LOCATION}
    Const A_DATAPOOL_LOCATION = 'Datapool Location';
    {$DEFINE LA_DATAPOOL_LOCATION}
    Const LA_DATAPOOL_LOCATION = 'D\0a\0t\0a\0p\0o\0o\0l\0 \0L\0o\0c\0a\0t\0i\0o\0n\0\0';
    {$DEFINE A_PRINTER_MODEL}
    Const A_PRINTER_MODEL = 'Printer Model';
    {$DEFINE LA_PRINTER_MODEL}
    Const LA_PRINTER_MODEL = 'P\0r\0i\0n\0t\0e\0r\0 \0M\0o\0d\0e\0l\0\0';
    {$DEFINE A_PRINTER_MANUFACTURER}
    Const A_PRINTER_MANUFACTURER = 'Printer Manufacturer';
    {$DEFINE LA_PRINTER_MANUFACTURER}
    Const LA_PRINTER_MANUFACTURER = 'P\0r\0i\0n\0t\0e\0r\0 \0M\0a\0n\0u\0f\0a\0c\0t\0u\0r\0e\0r\0\0';
    {$DEFINE A_SIDES_SUPPORTED}
    Const A_SIDES_SUPPORTED = 'Sides Supported';
    {$DEFINE LA_SIDES_SUPPORTED}
    Const LA_SIDES_SUPPORTED = 'S\0i\0d\0e\0s\0 \0S\0u\0p\0p\0o\0r\0t\0e\0d\0\0';
    {$DEFINE A_NDPS_PRINTER_SIBLING_LIST}
    Const A_NDPS_PRINTER_SIBLING_LIST = 'NDPS Printer Siblings';
    {$DEFINE LA_NDPS_PRINTER_SIBLING_LIST}
    Const LA_NDPS_PRINTER_SIBLING_LIST = 'N\0D\0P\0S\0 \0P\0r\0i\0n\0t\0e\0r\0 \0S\0i\0b\0l\0i\0n\0g\0s\0\0';
    (*
// NDPS Broker Object Attributes
*)
    {$DEFINE A_DELIVERY_METHODS_INSTALLED}
    Const A_DELIVERY_METHODS_INSTALLED = 'Delivery Methods Installed';
    {$DEFINE LA_DELIVERY_METHODS_INSTALLED}
    Const LA_DELIVERY_METHODS_INSTALLED = 'D\0e\0l\0i\0v\0e\0r\0y\0 \0M\0e\0t\0h\0o\0d\0s\0 \0I\0n\0s\0t\0a\0l\0l\0e\0d\0\0';
    {$DEFINE A_MHS_SEND_DIRECTORY_PATH}
    Const A_MHS_SEND_DIRECTORY_PATH = 'MHS Send Directory Path';
    {$DEFINE LA_MHS_SEND_DIRECTORY_PATH}
    Const LA_MHS_SEND_DIRECTORY_PATH = 'M\0H\0S\0 \0S\0e\0n\0d\0 \0D\0i\0r\0e\0c\0t\0o\0r\0y\0 \0P\0a\0t\0h\0\0';
    {$DEFINE A_MHS_SEND_DIRECTORY_VOLUME}
    Const A_MHS_SEND_DIRECTORY_VOLUME = 'MHS Send Directory Volume';
    {$DEFINE LA_MHS_SEND_DIRECTORY_VOLUME}
    Const LA_MHS_SEND_DIRECTORY_VOLUME = 'M\0H\0S\0 \0S\0e\0n\0d\0 \0D\0i\0r\0e\0c\0t\0o\0r\0y\0 \0V\0o\0l\0u\0m\0e\0\0';
    {$DEFINE A_GW_APIGW_DIRECTORY_PATH}
    Const A_GW_APIGW_DIRECTORY_PATH = 'GW API Gateway Directory Path';
    {$DEFINE LA_GW_APIGW_DIRECTORY_PATH}
    Const LA_GW_APIGW_DIRECTORY_PATH = 'G\0W\0 \0A\0P\0I\0 \0G\0a\0t\0e\0w\0a\0y\0 \0D\0i\0r\0e\0c\0t\0o\0r\0y\0 \0P\0a\0t\0h\0\0';
    {$DEFINE A_GW_APIGW_DIRECTORY_VOLUME}
    Const A_GW_APIGW_DIRECTORY_VOLUME = 'GW API Gateway Directory Volume';
    {$DEFINE LA_GW_APIGW_DIRECTORY_VOLUME}
    Const LA_GW_APIGW_DIRECTORY_VOLUME = 'G\0W\0 \0A\0P\0I\0 \0G\0a\0t\0e\0w\0a\0y\0 \0D\0i\0r\0e\0c\0t\0o\0r\0y\0 \0V\0o\0l\0u\0m\0e\0\0';
    {$DEFINE A_NOTIFICATION_SERVICE_ENABLED}
    Const A_NOTIFICATION_SERVICE_ENABLED = 'Notification Service Enabled';
    {$DEFINE LA_NOTIFICATION_SERVICE_ENABLED}
    Const LA_NOTIFICATION_SERVICE_ENABLED = 'N\0o\0t\0i\0f\0i\0c\0a\0t\0i\0o\0n\0 \0S\0e\0r\0v\0i\0c\0e\0 \0E\0n\0a\0b\0l\0e\0d\0\0';
    {$DEFINE A_REGISTRY_ADVERTISING_NAME}
    Const A_REGISTRY_ADVERTISING_NAME = 'Registry Advertising Name';
    {$DEFINE LA_REGISTRY_ADVERTISING_NAME}
    Const LA_REGISTRY_ADVERTISING_NAME = 'R\0e\0g\0i\0s\0t\0r\0y\0 \0A\0d\0v\0e\0r\0t\0i\0s\0i\0n\0g\0 \0N\0a\0m\0e\0\0';
    {$DEFINE A_REGISTRY_SERVICE_ENABLED}
    Const A_REGISTRY_SERVICE_ENABLED = 'Registry Service Enabled';
    {$DEFINE LA_REGISTRY_SERVICE_ENABLED}
    Const LA_REGISTRY_SERVICE_ENABLED = 'R\0e\0g\0i\0s\0t\0r\0y\0 \0S\0e\0r\0v\0i\0c\0e\0 \0E\0n\0a\0b\0l\0e\0d\0\0';
    {$DEFINE A_RESOURCE_MGMT_SERVICE_ENABLD}
    Const A_RESOURCE_MGMT_SERVICE_ENABLD = 'Resource Mgmt Service Enabled';
    {$DEFINE LA_RESOURCE_MGMT_SERVICE_ENABLD}
    Const LA_RESOURCE_MGMT_SERVICE_ENABLD = 'R\0e\0s\0o\0u\0r\0c\0e\0 \0M\0g\0m\0t\0 \0S\0e\0r\0v\0i\0c\0e\0 \0E\0n\0a\0b\0l\0e\0d\0\0';
    {$DEFINE A_RESOURCE_MGR_DATABASE_PATH}
    Const A_RESOURCE_MGR_DATABASE_PATH = 'Resource Mgr Database Path';
    {$DEFINE LA_RESOURCE_MGR_DATABASE_PATH}
    Const LA_RESOURCE_MGR_DATABASE_PATH = 'R\0e\0s\0o\0u\0r\0c\0e\0 \0M\0g\0r\0 \0D\0a\0t\0a\0b\0a\0s\0e\0 \0P\0a\0t\0h\0\0';
    {$DEFINE A_RESOURCE_MGR_DATABASE_VOLUME}
    Const A_RESOURCE_MGR_DATABASE_VOLUME = 'Resource Mgr Database Volume';
    {$DEFINE LA_RESOURCE_MGR_DATABASE_VOLUME}
    Const LA_RESOURCE_MGR_DATABASE_VOLUME = 'R\0e\0s\0o\0u\0r\0c\0e\0 \0M\0g\0r\0 \0D\0a\0t\0a\0b\0a\0s\0e\0 \0V\0o\0l\0u\0m\0e\0\0';
    {$DEFINE A_REGISTRY_NET_ADDRESS}
    Const A_REGISTRY_NET_ADDRESS = 'Registry Srvc Net Address';
    {$DEFINE LA_REGISTRY_NET_ADDRESS}
    Const LA_REGISTRY_NET_ADDRESS = 'R\0e\0g\0i\0s\0t\0r\0y\0 \0S\0r\0v\0c\0 \0N\0e\0t\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    {$DEFINE A_NOTIFY_NET_ADDRESS}
    Const A_NOTIFY_NET_ADDRESS = 'Notification Srvc Net Address';
    {$DEFINE LA_NOTIFY_NET_ADDRESS}
    Const LA_NOTIFY_NET_ADDRESS = 'N\0o\0t\0i\0f\0i\0c\0a\0t\0i\0o\0n\0 \0S\0r\0v\0c\0 \0N\0e\0t\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    {$DEFINE A_RES_MGMT_NET_ADDRESS}
    Const A_RES_MGMT_NET_ADDRESS = 'Resource Mgmt Srvc Net Address';
    {$DEFINE LA_RES_MGMT_NET_ADDRESS}
    Const LA_RES_MGMT_NET_ADDRESS = 'R\0e\0s\0o\0u\0r\0c\0e\0 \0M\0g\0m\0t\0 \0S\0r\0v\0c\0 \0N\0e\0t\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    (*
// NDPS Manager Object Attributes
*)
    {$DEFINE A_PRINTER_TO_PA_ID_MAPPINGS}
    Const A_PRINTER_TO_PA_ID_MAPPINGS = 'Printer to PA ID Mappings';
    {$DEFINE LA_PRINTER_TO_PA_ID_MAPPINGS}
    Const LA_PRINTER_TO_PA_ID_MAPPINGS = 'P\0r\0i\0n\0t\0e\0r\0 \0t\0o\0 \0P\0A\0 \0I\0D\0 \0M\0a\0p\0p\0i\0n\0g\0s\0\0';
    {$DEFINE A_DATAPOOL_LOCATIONS}
    Const A_DATAPOOL_LOCATIONS = 'Datapool Locations';
    {$DEFINE LA_DATAPOOL_LOCATIONS}
    Const LA_DATAPOOL_LOCATIONS = 'D\0a\0t\0a\0p\0o\0o\0l\0 \0L\0o\0c\0a\0t\0i\0o\0n\0s\0\0';
    {$DEFINE A_DATABASE_VOLUME_NAME}
    Const A_DATABASE_VOLUME_NAME = 'Database Volume Name';
    {$DEFINE LA_DATABASE_VOLUME_NAME}
    Const LA_DATABASE_VOLUME_NAME = 'D\0a\0t\0a\0b\0a\0s\0e\0 \0V\0o\0l\0u\0m\0e\0 \0N\0a\0m\0e\0\0';
    {$DEFINE A_DATABASE_DIR_PATH}
    Const A_DATABASE_DIR_PATH = 'Database Dir Path';
    {$DEFINE LA_DATABASE_DIR_PATH}
    Const LA_DATABASE_DIR_PATH = 'D\0a\0t\0a\0b\0a\0s\0e\0 \0D\0i\0r\0 \0P\0a\0t\0h\0\0';
    {$DEFINE A_MANAGER_STATUS}
    Const A_MANAGER_STATUS = 'NDPS Manager Status';
    {$DEFINE LA_MANAGER_STATUS}
    Const LA_MANAGER_STATUS = 'N\0D\0P\0S\0 \0M\0a\0n\0a\0g\0e\0r\0 \0S\0t\0a\0t\0u\0s\0\0';
    (*
// NDPS Object Class names
*)
    {$DEFINE C_NDPS_PRINTER}
    Const C_NDPS_PRINTER = 'NDPS Printer';
    {$DEFINE LC_NDPS_PRINTER}
    Const LC_NDPS_PRINTER = 'N\0D\0P\0S\0 \0P\0r\0i\0n\0t\0e\0r\0\0';
    {$DEFINE C_NDPS_MANAGER}
    Const C_NDPS_MANAGER = 'NDPS Manager';
    {$DEFINE LC_NDPS_MANAGER}
    Const LC_NDPS_MANAGER = 'N\0D\0P\0S\0 \0M\0a\0n\0a\0g\0e\0r\0\0';
    {$DEFINE C_NDPS_BROKER}
    Const C_NDPS_BROKER = 'NDPS Broker';
    {$DEFINE LC_NDPS_BROKER}
    Const LC_NDPS_BROKER = 'N\0D\0P\0S\0 \0B\0r\0o\0k\0e\0r\0\0';
    (*
   // Define the lengths for the attributes that have the DS_SIZED_ATTR
   // constraint. These values will need to be adjusted.
   *)
    {$DEFINE A_MAX_STRING_LENGTH}
    Const A_MAX_STRING_LENGTH = 128;
    {$DEFINE A_MAX_SPEED}
    Const A_MAX_SPEED = 10000;
    (*
// Definitions stolen from NWDSDEFS.H and made Unicode.
*)
    (* special entry names in ACLs *)
    {$DEFINE LDS_ROOT_NAME}
    Const LDS_ROOT_NAME = '[\0R\0o\0o\0t\0]\0\0';
    {$DEFINE LDS_PUBLIC_NAME}
    Const LDS_PUBLIC_NAME = '[\0P\0u\0b\0l\0i\0c\0]\0\0';
    {$DEFINE LDS_MASK_NAME}
    Const LDS_MASK_NAME = '[\0I\0n\0h\0e\0r\0i\0t\0a\0n\0c\0e\0 \0M\0a\0s\0k\0]\0\0';
    {$DEFINE LDS_CREATOR_NAME}
    Const LDS_CREATOR_NAME = '[\0C\0r\0e\0a\0t\0o\0r\0]\0\0';
    {$DEFINE LDS_SELF_NAME}
    Const LDS_SELF_NAME = '[\0S\0e\0l\0f\0]\0\0';
    (* special attribute names in ACLs*)
    {$DEFINE LDS_ALL_ATTRS_NAME}
    Const LDS_ALL_ATTRS_NAME = '[\0A\0l\0l\0 \0A\0t\0t\0r\0i\0b\0u\0t\0e\0s\0 \0R\0i\0g\0h\0t\0s\0]\0\0';
    {$DEFINE LDS_SMS_RIGHTS_NAME}
    Const LDS_SMS_RIGHTS_NAME = '[\0S\0M\0S\0 \0R\0i\0g\0h\0t\0s\0]\0\0';
    {$DEFINE LDS_ENTRY_RIGHTS_NAME}
    Const LDS_ENTRY_RIGHTS_NAME = '[\0E\0n\0t\0r\0y\0 \0R\0i\0g\0h\0t\0s\0]\0\0';
    (*
// Definitions stolen from NWDSNMTP.H and made Unicode.
*)
    {$DEFINE LC_AFP_SERVER}
    Const LC_AFP_SERVER = 'A\0F\0P\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LC_ALIAS}
    Const LC_ALIAS = 'A\0l\0i\0a\0s\0\0';
    {$DEFINE LC_BINDERY_OBJECT}
    Const LC_BINDERY_OBJECT = 'B\0i\0n\0d\0e\0r\0y\0 \0O\0b\0j\0e\0c\0t\0\0';
    {$DEFINE LC_BINDERY_QUEUE}
    Const LC_BINDERY_QUEUE = 'B\0i\0n\0d\0e\0r\0y\0 \0Q\0u\0e\0u\0e\0\0';
    {$DEFINE LC_COMPUTER}
    Const LC_COMPUTER = 'C\0o\0m\0p\0u\0t\0e\0r\0\0';
    {$DEFINE LC_COUNTRY}
    Const LC_COUNTRY = 'C\0o\0u\0n\0t\0r\0y\0\0';
    {$DEFINE LC_DEVICE}
    Const LC_DEVICE = 'D\0e\0v\0i\0c\0e\0\0';
    {$DEFINE LC_DIRECTORY_MAP}
    Const LC_DIRECTORY_MAP = 'D\0i\0r\0e\0c\0t\0o\0r\0y\0 \0M\0a\0p\0\0';
    {$DEFINE LC_EXTERNAL_ENTITY}
    Const LC_EXTERNAL_ENTITY = 'E\0x\0t\0e\0r\0n\0a\0l\0 \0E\0n\0t\0i\0t\0y\0\0';
    {$DEFINE LC_GROUP}
    Const LC_GROUP = 'G\0r\0o\0u\0p\0\0';
    {$DEFINE LC_LIST}
    Const LC_LIST = 'L\0i\0s\0t\0\0';
    {$DEFINE LC_LOCALITY}
    Const LC_LOCALITY = 'L\0o\0c\0a\0l\0i\0t\0y\0\0';
    {$DEFINE LC_MESSAGING_ROUTING_GROUP}
    Const LC_MESSAGING_ROUTING_GROUP = 'M\0e\0s\0s\0a\0g\0i\0n\0g\0 \0R\0o\0u\0t\0i\0n\0g\0 \0G\0r\0o\0u\0p\0\0';
    {$DEFINE LC_MESSAGING_SERVER}
    Const LC_MESSAGING_SERVER = 'M\0e\0s\0s\0a\0g\0i\0n\0g\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LC_NCP_SERVER}
    Const LC_NCP_SERVER = 'N\0C\0P\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LC_ORGANIZATION}
    Const LC_ORGANIZATION = 'O\0r\0g\0a\0n\0i\0z\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LC_ORGANIZATIONAL_PERSON}
    Const LC_ORGANIZATIONAL_PERSON = 'O\0r\0g\0a\0n\0i\0z\0a\0t\0i\0o\0n\0a\0l\0 \0P\0e\0r\0s\0o\0n\0\0';
    {$DEFINE LC_ORGANIZATIONAL_ROLE}
    Const LC_ORGANIZATIONAL_ROLE = 'O\0r\0g\0a\0n\0i\0z\0a\0t\0i\0o\0n\0a\0l\0 \0R\0o\0l\0e\0\0';
    {$DEFINE LC_ORGANIZATIONAL_UNIT}
    Const LC_ORGANIZATIONAL_UNIT = 'O\0r\0g\0a\0n\0i\0z\0a\0t\0i\0o\0n\0a\0l\0 \0U\0n\0i\0t\0\0';
    {$DEFINE LC_PARTITION}
    Const LC_PARTITION = 'P\0a\0r\0t\0i\0t\0i\0o\0n\0\0';
    {$DEFINE LC_PERSON}
    Const LC_PERSON = 'P\0e\0r\0s\0o\0n\0\0';
    {$DEFINE LC_PRINT_SERVER}
    Const LC_PRINT_SERVER = 'P\0r\0i\0n\0t\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LC_PRINTER}
    Const LC_PRINTER = 'P\0r\0i\0n\0t\0e\0r\0\0';
    {$DEFINE LC_PROFILE}
    Const LC_PROFILE = 'P\0r\0o\0f\0i\0l\0e\0\0';
    {$DEFINE LC_QUEUE}
    Const LC_QUEUE = 'Q\0u\0e\0u\0e\0\0';
    {$DEFINE LC_RESOURCE}
    Const LC_RESOURCE = 'R\0e\0s\0o\0u\0r\0c\0e\0\0';
    {$DEFINE LC_SERVER}
    Const LC_SERVER = 'S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LC_TOP}
    Const LC_TOP = 'T\0o\0p\0\0';
    {$DEFINE LC_UNKNOWN}
    Const LC_UNKNOWN = 'U\0n\0k\0n\0o\0w\0n\0\0';
    {$DEFINE LC_USER}
    Const LC_USER = 'U\0s\0e\0r\0\0';
    {$DEFINE LC_VOLUME}
    Const LC_VOLUME = 'V\0o\0l\0u\0m\0e\0\0';
    {$DEFINE LA_ACCOUNT_BALANCE}
    Const LA_ACCOUNT_BALANCE = 'A\0c\0c\0o\0u\0n\0t\0 \0B\0a\0l\0a\0n\0c\0e\0\0';
    {$DEFINE LA_ACL}
    Const LA_ACL = 'A\0C\0L\0\0';
    {$DEFINE LA_ALIASED_OBJECT_NAME}
    Const LA_ALIASED_OBJECT_NAME = 'A\0l\0i\0a\0s\0e\0d\0 \0O\0b\0j\0e\0c\0t\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_ALLOW_UNLIMITED_CREDIT}
    Const LA_ALLOW_UNLIMITED_CREDIT = 'A\0l\0l\0o\0w\0 \0U\0n\0l\0i\0m\0i\0t\0e\0d\0 \0C\0r\0e\0d\0i\0t\0\0';
    {$DEFINE LA_AUTHORITY_REVOCATION}
    Const LA_AUTHORITY_REVOCATION = 'A\0u\0t\0h\0o\0r\0i\0t\0y\0 \0R\0e\0v\0o\0c\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LA_BACK_LINK}
    Const LA_BACK_LINK = 'B\0a\0c\0k\0 \0L\0i\0n\0k\0\0';
    {$DEFINE LA_BINDERY_OBJECT_RESTRICTION}
    Const LA_BINDERY_OBJECT_RESTRICTION = 'B\0i\0n\0d\0e\0r\0y\0 \0O\0b\0j\0e\0c\0t\0 \0R\0e\0s\0t\0r\0i\0c\0t\0i\0o\0n\0\0';
    {$DEFINE LA_BINDERY_PROPERTY}
    Const LA_BINDERY_PROPERTY = 'B\0i\0n\0d\0e\0r\0y\0 \0P\0r\0o\0p\0e\0r\0t\0y\0\0';
    {$DEFINE LA_BINDERY_TYPE}
    Const LA_BINDERY_TYPE = 'B\0i\0n\0d\0e\0r\0y\0 \0T\0y\0p\0e\0\0';
    {$DEFINE LA_CARTRIDGE}
    Const LA_CARTRIDGE = 'C\0a\0r\0t\0r\0i\0d\0g\0e\0\0';
    {$DEFINE LA_CA_PRIVATE_KEY}
    Const LA_CA_PRIVATE_KEY = 'C\0A\0 \0P\0r\0i\0v\0a\0t\0e\0 \0K\0e\0y\0\0';
    {$DEFINE LA_CA_PUBLIC_KEY}
    Const LA_CA_PUBLIC_KEY = 'C\0A\0 \0P\0u\0b\0l\0i\0c\0 \0K\0e\0y\0\0';
    {$DEFINE LA_CERTIFICATE_REVOCATION}
    Const LA_CERTIFICATE_REVOCATION = 'C\0e\0r\0t\0i\0f\0i\0c\0a\0t\0e\0 \0R\0e\0v\0o\0c\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LA_CERTIFICATE_VALIDITY_INTERVL}
    Const LA_CERTIFICATE_VALIDITY_INTERVL = 'C\0e\0r\0t\0i\0f\0i\0c\0a\0t\0e\0 \0V\0a\0l\0i\0d\0i\0t\0y\0 \0I\0n\0t\0e\0r\0v\0a\0l\0\0';
    {$DEFINE LA_COMMON_NAME}
    Const LA_COMMON_NAME = 'C\0N\0\0';
    {$DEFINE LA_CONVERGENCE}
    Const LA_CONVERGENCE = 'C\0o\0n\0v\0e\0r\0g\0e\0n\0c\0e\0\0';
    {$DEFINE LA_COUNTRY_NAME}
    Const LA_COUNTRY_NAME = 'C\0\0';
    {$DEFINE LA_CROSS_CERTIFICATE_PAIR}
    Const LA_CROSS_CERTIFICATE_PAIR = 'C\0r\0o\0s\0s\0 \0C\0e\0r\0t\0i\0f\0i\0c\0a\0t\0e\0 \0P\0a\0i\0r\0\0';
    {$DEFINE LA_DEFAULT_QUEUE}
    Const LA_DEFAULT_QUEUE = 'D\0e\0f\0a\0u\0l\0t\0 \0Q\0u\0e\0u\0e\0\0';
    {$DEFINE LA_DESCRIPTION}
    Const LA_DESCRIPTION = 'D\0e\0s\0c\0r\0i\0p\0t\0i\0o\0n\0\0';
    {$DEFINE LA_DETECT_INTRUDER}
    Const LA_DETECT_INTRUDER = 'D\0e\0t\0e\0c\0t\0 \0I\0n\0t\0r\0u\0d\0e\0r\0\0';
    {$DEFINE LA_DEVICE}
    Const LA_DEVICE = 'D\0e\0v\0i\0c\0e\0\0';
    {$DEFINE LA_DS_REVISION}
    Const LA_DS_REVISION = 'D\0S\0 \0R\0e\0v\0i\0s\0i\0o\0n\0\0';
    {$DEFINE LA_EMAIL_ADDRESS}
    Const LA_EMAIL_ADDRESS = 'E\0M\0a\0i\0l\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    {$DEFINE LA_EXTERNAL_NAME}
    Const LA_EXTERNAL_NAME = 'E\0x\0t\0e\0r\0n\0a\0l\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_EXTERNAL_SYNCHRONIZER}
    Const LA_EXTERNAL_SYNCHRONIZER = 'E\0x\0t\0e\0r\0n\0a\0l\0 \0S\0y\0n\0c\0h\0r\0o\0n\0i\0z\0e\0r\0\0';
    {$DEFINE LA_FACSIMILE_TELEPHONE_NUMBER}
    Const LA_FACSIMILE_TELEPHONE_NUMBER = 'F\0a\0c\0s\0i\0m\0i\0l\0e\0 \0T\0e\0l\0e\0p\0h\0o\0n\0e\0 \0N\0u\0m\0b\0e\0r\0\0';
    {$DEFINE LA_FULL_NAME}
    Const LA_FULL_NAME = 'F\0u\0l\0l\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_GENERATIONAL_QUALIFIER}
    Const LA_GENERATIONAL_QUALIFIER = 'G\0e\0n\0e\0r\0a\0t\0i\0o\0n\0a\0l\0 \0Q\0u\0a\0l\0i\0f\0i\0e\0r\0\0';
    {$DEFINE LA_GID}
    Const LA_GID = 'G\0I\0D\0\0';
    {$DEFINE LA_GIVEN_NAME}
    Const LA_GIVEN_NAME = 'G\0i\0v\0e\0n\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_GROUP_MEMBERSHIP}
    Const LA_GROUP_MEMBERSHIP = 'G\0r\0o\0u\0p\0 \0M\0e\0m\0b\0e\0r\0s\0h\0i\0p\0\0';
    {$DEFINE LA_HIGH_SYNC_INTERVAL}
    Const LA_HIGH_SYNC_INTERVAL = 'H\0i\0g\0h\0 \0C\0o\0n\0v\0e\0r\0g\0e\0n\0c\0e\0 \0S\0y\0n\0c\0 \0I\0n\0t\0e\0r\0v\0a\0l\0\0';
    {$DEFINE LA_HIGHER_PRIVILEGES}
    Const LA_HIGHER_PRIVILEGES = 'H\0i\0g\0h\0e\0r\0 \0P\0r\0i\0v\0i\0l\0e\0g\0e\0s\0\0';
    {$DEFINE LA_HOME_DIRECTORY}
    Const LA_HOME_DIRECTORY = 'H\0o\0m\0e\0 \0D\0i\0r\0e\0c\0t\0o\0r\0y\0\0';
    {$DEFINE LA_HOST_DEVICE}
    Const LA_HOST_DEVICE = 'H\0o\0s\0t\0 \0D\0e\0v\0i\0c\0e\0\0';
    {$DEFINE LA_HOST_RESOURCE_NAME}
    Const LA_HOST_RESOURCE_NAME = 'H\0o\0s\0t\0 \0R\0e\0s\0o\0u\0r\0c\0e\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_HOST_SERVER}
    Const LA_HOST_SERVER = 'H\0o\0s\0t\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LA_INHERITED_ACL}
    Const LA_INHERITED_ACL = 'I\0n\0h\0e\0r\0i\0t\0e\0d\0 \0A\0C\0L\0\0';
    {$DEFINE LA_INITIALS}
    Const LA_INITIALS = 'I\0n\0i\0t\0i\0a\0l\0s\0\0';
    {$DEFINE LA_INTRUDER_ATTEMPT_RESET_NTRVL}
    Const LA_INTRUDER_ATTEMPT_RESET_NTRVL = 'I\0n\0t\0r\0u\0d\0e\0r\0 \0A\0t\0t\0e\0m\0p\0t\0 \0R\0e\0s\0e\0t\0 \0I\0n\0t\0e\0r\0v\0a\0l\0\0';
    {$DEFINE LA_INTRUDER_LOCKOUT_RESET_NTRVL}
    Const LA_INTRUDER_LOCKOUT_RESET_NTRVL = 'I\0n\0t\0r\0u\0d\0e\0r\0 \0L\0o\0c\0k\0o\0u\0t\0 \0R\0e\0s\0e\0t\0 \0I\0n\0t\0e\0r\0v\0a\0l\0\0';
    {$DEFINE LA_LOCALITY_NAME}
    Const LA_LOCALITY_NAME = 'L\0\0';
    {$DEFINE LA_LANGUAGE}
    Const LA_LANGUAGE = 'L\0a\0n\0g\0u\0a\0g\0e\0\0';
    {$DEFINE LA_LAST_LOGIN_TIME}
    Const LA_LAST_LOGIN_TIME = 'L\0a\0s\0t\0 \0L\0o\0g\0i\0n\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_LAST_REFERENCED_TIME}
    Const LA_LAST_REFERENCED_TIME = 'L\0a\0s\0t\0 \0R\0e\0f\0e\0r\0e\0n\0c\0e\0d\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_LOCKED_BY_INTRUDER}
    Const LA_LOCKED_BY_INTRUDER = 'L\0o\0c\0k\0e\0d\0 \0B\0y\0 \0I\0n\0t\0r\0u\0d\0e\0r\0\0';
    {$DEFINE LA_LOCKOUT_AFTER_DETECTION}
    Const LA_LOCKOUT_AFTER_DETECTION = 'L\0o\0c\0k\0o\0u\0t\0 \0A\0f\0t\0e\0r\0 \0D\0e\0t\0e\0c\0t\0i\0o\0n\0\0';
    {$DEFINE LA_LOGIN_ALLOWED_TIME_MAP}
    Const LA_LOGIN_ALLOWED_TIME_MAP = 'L\0o\0g\0i\0n\0 \0A\0l\0l\0o\0w\0e\0d\0 \0T\0i\0m\0e\0 \0M\0a\0p\0\0';
    {$DEFINE LA_LOGIN_DISABLED}
    Const LA_LOGIN_DISABLED = 'L\0o\0g\0i\0n\0 \0D\0i\0s\0a\0b\0l\0e\0d\0\0';
    {$DEFINE LA_LOGIN_EXPIRATION_TIME}
    Const LA_LOGIN_EXPIRATION_TIME = 'L\0o\0g\0i\0n\0 \0E\0x\0p\0i\0r\0a\0t\0i\0o\0n\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_LOGIN_GRACE_LIMIT}
    Const LA_LOGIN_GRACE_LIMIT = 'L\0o\0g\0i\0n\0 \0G\0r\0a\0c\0e\0 \0L\0i\0m\0i\0t\0\0';
    {$DEFINE LA_LOGIN_GRACE_REMAINING}
    Const LA_LOGIN_GRACE_REMAINING = 'L\0o\0g\0i\0n\0 \0G\0r\0a\0c\0e\0 \0R\0e\0m\0a\0i\0n\0i\0n\0g\0\0';
    {$DEFINE LA_LOGIN_INTRUDER_ADDRESS}
    Const LA_LOGIN_INTRUDER_ADDRESS = 'L\0o\0g\0i\0n\0 \0I\0n\0t\0r\0u\0d\0e\0r\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    {$DEFINE LA_LOGIN_INTRUDER_ATTEMPTS}
    Const LA_LOGIN_INTRUDER_ATTEMPTS = 'L\0o\0g\0i\0n\0 \0I\0n\0t\0r\0u\0d\0e\0r\0 \0A\0t\0t\0e\0m\0p\0t\0s\0\0';
    {$DEFINE LA_LOGIN_INTRUDER_LIMIT}
    Const LA_LOGIN_INTRUDER_LIMIT = 'L\0o\0g\0i\0n\0 \0I\0n\0t\0r\0u\0d\0e\0r\0 \0L\0i\0m\0i\0t\0\0';
    {$DEFINE LA_LOGIN_INTRUDER_RESET_TIME}
    Const LA_LOGIN_INTRUDER_RESET_TIME = 'L\0o\0g\0i\0n\0 \0I\0n\0t\0r\0u\0d\0e\0r\0 \0R\0e\0s\0e\0t\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_LOGIN_MAXIMUM_SIMULTANEOUS}
    Const LA_LOGIN_MAXIMUM_SIMULTANEOUS = 'L\0o\0g\0i\0n\0 \0M\0a\0x\0i\0m\0u\0m\0 \0S\0i\0m\0u\0l\0t\0a\0n\0e\0o\0u\0s\0\0';
    {$DEFINE LA_LOGIN_SCRIPT}
    Const LA_LOGIN_SCRIPT = 'L\0o\0g\0i\0n\0 \0S\0c\0r\0i\0p\0t\0\0';
    {$DEFINE LA_LOGIN_TIME}
    Const LA_LOGIN_TIME = 'L\0o\0g\0i\0n\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_LOW_RESET_TIME}
    Const LA_LOW_RESET_TIME = 'L\0o\0w\0 \0C\0o\0n\0v\0e\0r\0g\0e\0n\0c\0e\0 \0R\0e\0s\0e\0t\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_LOW_SYNC_INTERVAL}
    Const LA_LOW_SYNC_INTERVAL = 'L\0o\0w\0 \0C\0o\0n\0v\0e\0r\0g\0e\0n\0c\0e\0 \0S\0y\0n\0c\0 \0I\0n\0t\0e\0r\0v\0a\0l\0\0';
    {$DEFINE LA_MAILBOX_ID}
    Const LA_MAILBOX_ID = 'M\0a\0i\0l\0b\0o\0x\0 \0I\0D\0\0';
    {$DEFINE LA_MAILBOX_LOCATION}
    Const LA_MAILBOX_LOCATION = 'M\0a\0i\0l\0b\0o\0x\0 \0L\0o\0c\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LA_MEMBER}
    Const LA_MEMBER = 'M\0e\0m\0b\0e\0r\0\0';
    {$DEFINE LA_MEMORY}
    Const LA_MEMORY = 'M\0e\0m\0o\0r\0y\0\0';
    {$DEFINE LA_MESSAGE_SERVER}
    Const LA_MESSAGE_SERVER = 'M\0e\0s\0s\0a\0g\0e\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LA_MESSAGING_DATABASE_LOCATION}
    Const LA_MESSAGING_DATABASE_LOCATION = 'M\0e\0s\0s\0a\0g\0i\0n\0g\0 \0D\0a\0t\0a\0b\0a\0s\0e\0 \0L\0o\0c\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LA_MESSAGING_ROUTING_GROUP}
    Const LA_MESSAGING_ROUTING_GROUP = 'M\0e\0s\0s\0a\0g\0i\0n\0g\0 \0R\0o\0u\0t\0i\0n\0g\0 \0G\0r\0o\0u\0p\0\0';
    {$DEFINE LA_MESSAGING_SERVER}
    Const LA_MESSAGING_SERVER = 'M\0e\0s\0s\0a\0g\0i\0n\0g\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LA_MESSAGING_SERVER_TYPE}
    Const LA_MESSAGING_SERVER_TYPE = 'M\0e\0s\0s\0a\0g\0i\0n\0g\0 \0S\0e\0r\0v\0e\0r\0 \0T\0y\0p\0e\0\0';
    {$DEFINE LA_MINIMUM_ACCOUNT_BALANCE}
    Const LA_MINIMUM_ACCOUNT_BALANCE = 'M\0i\0n\0i\0m\0u\0m\0 \0A\0c\0c\0o\0u\0n\0t\0 \0B\0a\0l\0a\0n\0c\0e\0\0';
    {$DEFINE LA_NETWORK_ADDRESS}
    Const LA_NETWORK_ADDRESS = 'N\0e\0t\0w\0o\0r\0k\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    {$DEFINE LA_NETWORK_ADDRESS_RESTRICTION}
    Const LA_NETWORK_ADDRESS_RESTRICTION = 'N\0e\0t\0w\0o\0r\0k\0 \0A\0d\0d\0r\0e\0s\0s\0 \0R\0e\0s\0t\0r\0i\0c\0t\0i\0o\0n\0\0';
    {$DEFINE LA_NNS_DOMAIN}
    Const LA_NNS_DOMAIN = 'N\0N\0S\0 \0D\0o\0m\0a\0i\0n\0\0';
    {$DEFINE LA_NOTIFY}
    Const LA_NOTIFY = 'N\0o\0t\0i\0f\0y\0\0';
    {$DEFINE LA_OBITUARY}
    Const LA_OBITUARY = 'O\0b\0i\0t\0u\0a\0r\0y\0\0';
    {$DEFINE LA_ORGANIZATION_NAME}
    Const LA_ORGANIZATION_NAME = 'O\0\0';
    {$DEFINE LA_OBJECT_CLASS}
    Const LA_OBJECT_CLASS = 'O\0b\0j\0e\0c\0t\0 \0C\0l\0a\0s\0s\0\0';
    {$DEFINE LA_OPERATOR}
    Const LA_OPERATOR = 'O\0p\0e\0r\0a\0t\0o\0r\0\0';
    {$DEFINE LA_ORGANIZATIONAL_UNIT_NAME}
    Const LA_ORGANIZATIONAL_UNIT_NAME = 'O\0U\0\0';
    {$DEFINE LA_OWNER}
    Const LA_OWNER = 'O\0w\0n\0e\0r\0\0';
    {$DEFINE LA_PAGE_DESCRIPTION_LANGUAGE}
    Const LA_PAGE_DESCRIPTION_LANGUAGE = 'P\0a\0g\0e\0 \0D\0e\0s\0c\0r\0i\0p\0t\0i\0o\0n\0 \0L\0a\0n\0g\0u\0a\0g\0e\0\0';
    {$DEFINE LA_PARTITION_CONTROL}
    Const LA_PARTITION_CONTROL = 'P\0a\0r\0t\0i\0t\0i\0o\0n\0 \0C\0o\0n\0t\0r\0o\0l\0\0';
    {$DEFINE LA_PARTITION_CREATION_TIME}
    Const LA_PARTITION_CREATION_TIME = 'P\0a\0r\0t\0i\0t\0i\0o\0n\0 \0C\0r\0e\0a\0t\0i\0o\0n\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_PASSWORD_ALLOW_CHANGE}
    Const LA_PASSWORD_ALLOW_CHANGE = 'P\0a\0s\0s\0w\0o\0r\0d\0 \0A\0l\0l\0o\0w\0 \0C\0h\0a\0n\0g\0e\0\0';
    {$DEFINE LA_PASSWORD_EXPIRATION_INTERVAL}
    Const LA_PASSWORD_EXPIRATION_INTERVAL = 'P\0a\0s\0s\0w\0o\0r\0d\0 \0E\0x\0p\0i\0r\0a\0t\0i\0o\0n\0 \0I\0n\0t\0e\0r\0v\0a\0l\0\0';
    {$DEFINE LA_PASSWORD_EXPIRATION_TIME}
    Const LA_PASSWORD_EXPIRATION_TIME = 'P\0a\0s\0s\0w\0o\0r\0d\0 \0E\0x\0p\0i\0r\0a\0t\0i\0o\0n\0 \0T\0i\0m\0e\0\0';
    {$DEFINE LA_PASSWORD_MINIMUM_LENGTH}
    Const LA_PASSWORD_MINIMUM_LENGTH = 'P\0a\0s\0s\0w\0o\0r\0d\0 \0M\0i\0n\0i\0m\0u\0m\0 \0L\0e\0n\0g\0t\0h\0\0';
    {$DEFINE LA_PASSWORD_REQUIRED}
    Const LA_PASSWORD_REQUIRED = 'P\0a\0s\0s\0w\0o\0r\0d\0 \0R\0e\0q\0u\0i\0r\0e\0d\0\0';
    {$DEFINE LA_PASSWORD_UNIQUE_REQUIRED}
    Const LA_PASSWORD_UNIQUE_REQUIRED = 'P\0a\0s\0s\0w\0o\0r\0d\0 \0U\0n\0i\0q\0u\0e\0 \0R\0e\0q\0u\0i\0r\0e\0d\0\0';
    {$DEFINE LA_PASSWORDS_USED}
    Const LA_PASSWORDS_USED = 'P\0a\0s\0s\0w\0o\0r\0d\0s\0 \0U\0s\0e\0d\0\0';
    {$DEFINE LA_PATH}
    Const LA_PATH = 'P\0a\0t\0h\0\0';
    {$DEFINE LA_PHYSICAL_DELIVERY_OFFICE_NAM}
    Const LA_PHYSICAL_DELIVERY_OFFICE_NAM = 'P\0h\0y\0s\0i\0c\0a\0l\0 \0D\0e\0l\0i\0v\0e\0r\0y\0 \0O\0f\0f\0i\0c\0e\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_POSTAL_ADDRESS}
    Const LA_POSTAL_ADDRESS = 'P\0o\0s\0t\0a\0l\0 \0A\0d\0d\0r\0e\0s\0s\0\0';
    {$DEFINE LA_POSTAL_CODE}
    Const LA_POSTAL_CODE = 'P\0o\0s\0t\0a\0l\0 \0C\0o\0d\0e\0\0';
    {$DEFINE LA_POSTAL_OFFICE_BOX}
    Const LA_POSTAL_OFFICE_BOX = 'P\0o\0s\0t\0a\0l\0 \0O\0f\0f\0i\0c\0e\0 \0B\0o\0x\0\0';
    {$DEFINE LA_POSTMASTER}
    Const LA_POSTMASTER = 'P\0o\0s\0t\0m\0a\0s\0t\0e\0r\0\0';
    {$DEFINE LA_PRINT_SERVER}
    Const LA_PRINT_SERVER = 'P\0r\0i\0n\0t\0 \0S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LA_PRIVATE_KEY}
    Const LA_PRIVATE_KEY = 'P\0r\0i\0v\0a\0t\0e\0 \0K\0e\0y\0\0';
    {$DEFINE LA_PRINTER}
    Const LA_PRINTER = 'P\0r\0i\0n\0t\0e\0r\0\0';
    {$DEFINE LA_PRINTER_CONFIGURATION}
    Const LA_PRINTER_CONFIGURATION = 'P\0r\0i\0n\0t\0e\0r\0 \0C\0o\0n\0f\0i\0g\0u\0r\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LA_PRINTER_CONTROL}
    Const LA_PRINTER_CONTROL = 'P\0r\0i\0n\0t\0e\0r\0 \0C\0o\0n\0t\0r\0o\0l\0\0';
    {$DEFINE LA_PRINT_JOB_CONFIGURATION}
    Const LA_PRINT_JOB_CONFIGURATION = 'P\0r\0i\0n\0t\0 \0J\0o\0b\0 \0C\0o\0n\0f\0i\0g\0u\0r\0a\0t\0i\0o\0n\0\0';
    {$DEFINE LA_PROFILE}
    Const LA_PROFILE = 'P\0r\0o\0f\0i\0l\0e\0\0';
    {$DEFINE LA_PROFILE_MEMBERSHIP}
    Const LA_PROFILE_MEMBERSHIP = 'P\0r\0o\0f\0i\0l\0e\0 \0M\0e\0m\0b\0e\0r\0s\0h\0i\0p\0\0';
    {$DEFINE LA_PUBLIC_KEY}
    Const LA_PUBLIC_KEY = 'P\0u\0b\0l\0i\0c\0 \0K\0e\0y\0\0';
    {$DEFINE LA_QUEUE}
    Const LA_QUEUE = 'Q\0u\0e\0u\0e\0\0';
    {$DEFINE LA_QUEUE_DIRECTORY}
    Const LA_QUEUE_DIRECTORY = 'Q\0u\0e\0u\0e\0 \0D\0i\0r\0e\0c\0t\0o\0r\0y\0\0';
    {$DEFINE LA_RECEIVED_UP_TO}
    Const LA_RECEIVED_UP_TO = 'R\0e\0c\0e\0i\0v\0e\0d\0 \0U\0p\0 \0T\0o\0\0';
    {$DEFINE LA_REFERENCE}
    Const LA_REFERENCE = 'R\0e\0f\0e\0r\0e\0n\0c\0e\0\0';
    {$DEFINE LA_REPLICA}
    Const LA_REPLICA = 'R\0e\0p\0l\0i\0c\0a\0\0';
    {$DEFINE LA_RESOURCE}
    Const LA_RESOURCE = 'R\0e\0s\0o\0u\0r\0c\0e\0\0';
    {$DEFINE LA_REVISION}
    Const LA_REVISION = 'R\0e\0v\0i\0s\0i\0o\0n\0\0';
    {$DEFINE LA_ROLE_OCCUPANT}
    Const LA_ROLE_OCCUPANT = 'R\0o\0l\0e\0 \0O\0c\0c\0u\0p\0a\0n\0t\0\0';
    {$DEFINE LA_STATE_OR_PROVINCE_NAME}
    Const LA_STATE_OR_PROVINCE_NAME = 'S\0\0';
    {$DEFINE LA_STREET_ADDRESS}
    Const LA_STREET_ADDRESS = 'S\0A\0\0';
    {$DEFINE LA_SAP_NAME}
    Const LA_SAP_NAME = 'S\0A\0P\0 \0N\0a\0m\0e\0\0';
    {$DEFINE LA_SECURITY_EQUALS}
    Const LA_SECURITY_EQUALS = 'S\0e\0c\0u\0r\0i\0t\0y\0 \0E\0q\0u\0a\0l\0s\0\0';
    {$DEFINE LA_SECURITY_FLAGS}
    Const LA_SECURITY_FLAGS = 'S\0e\0c\0u\0r\0i\0t\0y\0 \0F\0l\0a\0g\0s\0\0';
    {$DEFINE LA_SEE_ALSO}
    Const LA_SEE_ALSO = 'S\0e\0e\0 \0A\0l\0s\0o\0\0';
    {$DEFINE LA_SERIAL_NUMBER}
    Const LA_SERIAL_NUMBER = 'S\0e\0r\0i\0a\0l\0 \0N\0u\0m\0b\0e\0r\0\0';
    {$DEFINE LA_SERVER}
    Const LA_SERVER = 'S\0e\0r\0v\0e\0r\0\0';
    {$DEFINE LA_SERVER_HOLDS}
    Const LA_SERVER_HOLDS = 'S\0e\0r\0v\0e\0r\0 \0H\0o\0l\0d\0s\0\0';
    {$DEFINE LA_STATUS}
    Const LA_STATUS = 'S\0t\0a\0t\0u\0s\0\0';
    {$DEFINE LA_SUPPORTED_CONNECTIONS}
    Const LA_SUPPORTED_CONNECTIONS = 'S\0u\0p\0p\0o\0r\0t\0e\0d\0 \0C\0o\0n\0n\0e\0c\0t\0i\0o\0n\0s\0\0';
    {$DEFINE LA_SUPPORTED_GATEWAY}
    Const LA_SUPPORTED_GATEWAY = 'S\0u\0p\0p\0o\0r\0t\0e\0d\0 \0G\0a\0t\0e\0w\0a\0y\0\0';
    {$DEFINE LA_SUPPORTED_SERVICES}
    Const LA_SUPPORTED_SERVICES = 'S\0u\0p\0p\0o\0r\0t\0e\0d\0 \0S\0e\0r\0v\0i\0c\0e\0s\0\0';
    {$DEFINE LA_SUPPORTED_TYPEFACES}
    Const LA_SUPPORTED_TYPEFACES = 'S\0u\0p\0p\0o\0r\0t\0e\0d\0 \0T\0y\0p\0e\0f\0a\0c\0e\0s\0\0';
    {$DEFINE LA_SURNAME}
    Const LA_SURNAME = 'S\0u\0r\0n\0a\0m\0e\0\0';
    {$DEFINE LA_IN_SYNC_UP_TO}
    Const LA_IN_SYNC_UP_TO = 'S\0y\0n\0c\0h\0r\0o\0n\0i\0z\0e\0d\0 \0U\0p\0 \0T\0o\0\0';
    {$DEFINE LA_TELEPHONE_NUMBER}
    Const LA_TELEPHONE_NUMBER = 'T\0e\0l\0e\0p\0h\0o\0n\0e\0 \0N\0u\0m\0b\0e\0r\0\0';
    {$DEFINE LA_TITLE}
    Const LA_TITLE = 'T\0i\0t\0l\0e\0\0';
    {$DEFINE LA_TYPE_CREATOR_MAP}
    Const LA_TYPE_CREATOR_MAP = 'T\0y\0p\0e\0 \0C\0r\0e\0a\0t\0o\0r\0 \0M\0a\0p\0\0';
    {$DEFINE LA_UID}
    Const LA_UID = 'U\0I\0D\0\0';
    {$DEFINE LA_UNKNOWN}
    Const LA_UNKNOWN = 'U\0n\0k\0n\0o\0w\0n\0\0';
    {$DEFINE LA_UNKNOWN_BASE_CLASS}
    Const LA_UNKNOWN_BASE_CLASS = 'U\0n\0k\0n\0o\0w\0n\0 \0B\0a\0s\0e\0 \0C\0l\0a\0s\0s\0\0';
    {$DEFINE LA_USER}
    Const LA_USER = 'U\0s\0e\0r\0\0';
    {$DEFINE LA_VERSION}
    Const LA_VERSION = 'V\0e\0r\0s\0i\0o\0n\0\0';
    {$DEFINE LA_VOLUME}
    Const LA_VOLUME = 'V\0o\0l\0u\0m\0e\0\0';
{$ELSE}
    {$IFDEF  N_DEBUG }
        (* TC error *)
    {$ENDIF}
{$ENDIF}


