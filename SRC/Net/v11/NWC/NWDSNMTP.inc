(******************************************************************************

  %name: nwdsnmtp.h %
  %version: 4 %
  %date_modified: Wed Dec 18 12:07:50 1996 %
  $Copyright:

  Copyright (c) 1989-1995 Novell, Inc.  All Rights Reserved.                      

  THIS WORK IS  SUBJECT  TO  U.S.  AND  INTERNATIONAL  COPYRIGHT  LAWS  AND
  TREATIES.   NO  PART  OF  THIS  WORK MAY BE  USED,  PRACTICED,  PERFORMED
  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED,  ABRIDGED, CONDENSED,
  EXPANDED,  COLLECTED,  COMPILED,  LINKED,  RECAST, TRANSFORMED OR ADAPTED
  WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC. ANY USE OR EXPLOITATION
  OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT THE PERPETRATOR TO
  CRIMINAL AND CIVIL LIABILITY.$

 *****************************************************************************)

{$IFNDEF  NWDSNMTP_H }
    {$DEFINE NWDSNMTP_H}
    {$DEFINE C_AFP_SERVER}
    Const C_AFP_SERVER = 'AFP Server';
    {$DEFINE C_ALIAS}
    Const C_ALIAS = 'Alias';
    {$DEFINE C_BINDERY_OBJECT}
    Const C_BINDERY_OBJECT = 'Bindery Object';
    {$DEFINE C_BINDERY_QUEUE}
    Const C_BINDERY_QUEUE = 'Bindery Queue';
    {$DEFINE C_COMMEXEC}
    Const C_COMMEXEC = 'CommExec';
    {$DEFINE C_COMPUTER}
    Const C_COMPUTER = 'Computer';
    {$DEFINE C_COUNTRY}
    Const C_COUNTRY = 'Country';
    {$DEFINE C_DEVICE}
    Const C_DEVICE = 'Device';
    {$DEFINE C_DIRECTORY_MAP}
    Const C_DIRECTORY_MAP = 'Directory Map';
    {$DEFINE C_EXTERNAL_ENTITY}
    Const C_EXTERNAL_ENTITY = 'External Entity';
    {$DEFINE C_GROUP}
    Const C_GROUP = 'Group';
    {$DEFINE C_LIST}
    Const C_LIST = 'List';
    {$DEFINE C_LOCALITY}
    Const C_LOCALITY = 'Locality';
    {$DEFINE C_MESSAGE_ROUTING_GROUP}
    Const C_MESSAGE_ROUTING_GROUP = 'Message Routing Group';
    {$DEFINE C_MESSAGING_ROUTING_GROUP}
    Const C_MESSAGING_ROUTING_GROUP = 'Messaging Routing Group';
    {$DEFINE C_MESSAGING_SERVER}
    Const C_MESSAGING_SERVER = 'Messaging Server';
    {$DEFINE C_NCP_SERVER}
    Const C_NCP_SERVER = 'NCP Server';
    {$DEFINE C_ORGANIZATION}
    Const C_ORGANIZATION = 'Organization';
    {$DEFINE C_ORGANIZATIONAL_PERSON}
    Const C_ORGANIZATIONAL_PERSON = 'Organizational Person';
    {$DEFINE C_ORGANIZATIONAL_ROLE}
    Const C_ORGANIZATIONAL_ROLE = 'Organizational Role';
    {$DEFINE C_ORGANIZATIONAL_UNIT}
    Const C_ORGANIZATIONAL_UNIT = 'Organizational Unit';
    {$DEFINE C_PARTITION}
    Const C_PARTITION = 'Partition';
    {$DEFINE C_PERSON}
    Const C_PERSON = 'Person';
    {$DEFINE C_PRINT_SERVER}
    Const C_PRINT_SERVER = 'Print Server';
    {$DEFINE C_PRINTER}
    Const C_PRINTER = 'Printer';
    {$DEFINE C_PROFILE}
    Const C_PROFILE = 'Profile';
    {$DEFINE C_QUEUE}
    Const C_QUEUE = 'Queue';
    {$DEFINE C_RESOURCE}
    Const C_RESOURCE = 'Resource';
    {$DEFINE C_SERVER}
    Const C_SERVER = 'Server';
    {$DEFINE C_TOP}
    Const C_TOP = 'Top';
    {$DEFINE C_UNKNOWN}
    Const C_UNKNOWN = 'Unknown';
    {$DEFINE C_USER}
    Const C_USER = 'User';
    {$DEFINE C_VOLUME}
    Const C_VOLUME = 'Volume';
    {$DEFINE A_ACCOUNT_BALANCE}
    Const A_ACCOUNT_BALANCE = 'Account Balance';
    {$DEFINE A_ACL}
    Const A_ACL = 'ACL';
    {$DEFINE A_ALIASED_OBJECT_NAME}
    Const A_ALIASED_OBJECT_NAME = 'Aliased Object Name';
    {$DEFINE A_ALLOW_UNLIMITED_CREDIT}
    Const A_ALLOW_UNLIMITED_CREDIT = 'Allow Unlimited Credit';
    {$DEFINE A_AUTHORITY_REVOCATION}
    Const A_AUTHORITY_REVOCATION = 'Authority Revocation';
    {$DEFINE A_BACK_LINK}
    Const A_BACK_LINK = 'Back Link';
    {$DEFINE A_BINDERY_OBJECT_RESTRICTION}
    Const A_BINDERY_OBJECT_RESTRICTION = 'Bindery Object Restriction';
    {$DEFINE A_BINDERY_PROPERTY}
    Const A_BINDERY_PROPERTY = 'Bindery Property';
    {$DEFINE A_BINDERY_TYPE}
    Const A_BINDERY_TYPE = 'Bindery Type';
    {$DEFINE A_CARTRIDGE}
    Const A_CARTRIDGE = 'Cartridge';
    {$DEFINE A_CA_PRIVATE_KEY}
    Const A_CA_PRIVATE_KEY = 'CA Private Key';
    {$DEFINE A_CA_PUBLIC_KEY}
    Const A_CA_PUBLIC_KEY = 'CA Public Key';
    {$DEFINE A_CERTIFICATE_REVOCATION}
    Const A_CERTIFICATE_REVOCATION = 'Certificate Revocation';
    {$DEFINE A_CERTIFICATE_VALIDITY_INTERVAL}
    Const A_CERTIFICATE_VALIDITY_INTERVAL = 'Certificate Validity Interval';
    {$DEFINE A_COMMON_NAME}
    Const A_COMMON_NAME = 'CN';
    {$DEFINE A_CONVERGENCE}
    Const A_CONVERGENCE = 'Convergence';
    {$DEFINE A_COUNTRY_NAME}
    Const A_COUNTRY_NAME = 'C';
    {$DEFINE A_CROSS_CERTIFICATE_PAIR}
    Const A_CROSS_CERTIFICATE_PAIR = 'Cross Certificate Pair';
    {$DEFINE A_DEFAULT_QUEUE}
    Const A_DEFAULT_QUEUE = 'Default Queue';
    {$DEFINE A_DESCRIPTION}
    Const A_DESCRIPTION = 'Description';
    {$DEFINE A_DETECT_INTRUDER}
    Const A_DETECT_INTRUDER = 'Detect Intruder';
    {$DEFINE A_DEVICE}
    Const A_DEVICE = 'Device';
    {$DEFINE A_DS_REVISION}
    Const A_DS_REVISION = 'DS Revision';
    {$DEFINE A_EMAIL_ADDRESS}
    Const A_EMAIL_ADDRESS = 'EMail Address';
    {$DEFINE A_EQUIVALENT_TO_ME}
    Const A_EQUIVALENT_TO_ME = 'Equivalent To Me';
    {$DEFINE A_EXTERNAL_NAME}
    Const A_EXTERNAL_NAME = 'External Name';
    {$DEFINE A_EXTERNAL_SYNCHRONIZER}
    Const A_EXTERNAL_SYNCHRONIZER = 'External Synchronizer';
    {$DEFINE A_FACSIMILE_TELEPHONE_NUMBER}
    Const A_FACSIMILE_TELEPHONE_NUMBER = 'Facsimile Telephone Number';
    {$DEFINE A_FULL_NAME}
    Const A_FULL_NAME = 'Full Name';
    {$DEFINE A_GENERATIONAL_QUALIFIER}
    Const A_GENERATIONAL_QUALIFIER = 'Generational Qualifier';
    {$DEFINE A_GID}
    Const A_GID = 'GID';
    {$DEFINE A_GIVEN_NAME}
    Const A_GIVEN_NAME = 'Given Name';
    {$DEFINE A_GROUP_MEMBERSHIP}
    Const A_GROUP_MEMBERSHIP = 'Group Membership';
    {$DEFINE A_HIGH_SYNC_INTERVAL}
    Const A_HIGH_SYNC_INTERVAL = 'High Convergence Sync Interval';
    {$DEFINE A_HIGHER_PRIVILEGES}
    Const A_HIGHER_PRIVILEGES = 'Higher Privileges';
    {$DEFINE A_HOME_DIRECTORY}
    Const A_HOME_DIRECTORY = 'Home Directory';
    {$DEFINE A_HOST_DEVICE}
    Const A_HOST_DEVICE = 'Host Device';
    {$DEFINE A_HOST_RESOURCE_NAME}
    Const A_HOST_RESOURCE_NAME = 'Host Resource Name';
    {$DEFINE A_HOST_SERVER}
    Const A_HOST_SERVER = 'Host Server';
    {$DEFINE A_INHERITED_ACL}
    Const A_INHERITED_ACL = 'Inherited ACL';
    {$DEFINE A_INITIALS}
    Const A_INITIALS = 'Initials';
    {$DEFINE A_INTRUDER_ATTEMPT_RESET_INTRVL}
    Const A_INTRUDER_ATTEMPT_RESET_INTRVL = 'Intruder Attempt Reset Interval';
    {$DEFINE A_INTRUDER_LOCKOUT_RESET_INTRVL}
    Const A_INTRUDER_LOCKOUT_RESET_INTRVL = 'Intruder Lockout Reset Interval';
    {$DEFINE A_LOCALITY_NAME}
    Const A_LOCALITY_NAME = 'L';
    {$DEFINE A_LANGUAGE}
    Const A_LANGUAGE = 'Language';
    {$DEFINE A_LAST_LOGIN_TIME}
    Const A_LAST_LOGIN_TIME = 'Last Login Time';
    {$DEFINE A_LAST_REFERENCED_TIME}
    Const A_LAST_REFERENCED_TIME = 'Last Referenced Time';
    {$DEFINE A_LOCKED_BY_INTRUDER}
    Const A_LOCKED_BY_INTRUDER = 'Locked By Intruder';
    {$DEFINE A_LOCKOUT_AFTER_DETECTION}
    Const A_LOCKOUT_AFTER_DETECTION = 'Lockout After Detection';
    {$DEFINE A_LOGIN_ALLOWED_TIME_MAP}
    Const A_LOGIN_ALLOWED_TIME_MAP = 'Login Allowed Time Map';
    {$DEFINE A_LOGIN_DISABLED}
    Const A_LOGIN_DISABLED = 'Login Disabled';
    {$DEFINE A_LOGIN_EXPIRATION_TIME}
    Const A_LOGIN_EXPIRATION_TIME = 'Login Expiration Time';
    {$DEFINE A_LOGIN_GRACE_LIMIT}
    Const A_LOGIN_GRACE_LIMIT = 'Login Grace Limit';
    {$DEFINE A_LOGIN_GRACE_REMAINING}
    Const A_LOGIN_GRACE_REMAINING = 'Login Grace Remaining';
    {$DEFINE A_LOGIN_INTRUDER_ADDRESS}
    Const A_LOGIN_INTRUDER_ADDRESS = 'Login Intruder Address';
    {$DEFINE A_LOGIN_INTRUDER_ATTEMPTS}
    Const A_LOGIN_INTRUDER_ATTEMPTS = 'Login Intruder Attempts';
    {$DEFINE A_LOGIN_INTRUDER_LIMIT}
    Const A_LOGIN_INTRUDER_LIMIT = 'Login Intruder Limit';
    {$DEFINE A_LOGIN_INTRUDER_RESET_TIME}
    Const A_LOGIN_INTRUDER_RESET_TIME = 'Login Intruder Reset Time';
    {$DEFINE A_LOGIN_MAXIMUM_SIMULTANEOUS}
    Const A_LOGIN_MAXIMUM_SIMULTANEOUS = 'Login Maximum Simultaneous';
    {$DEFINE A_LOGIN_SCRIPT}
    Const A_LOGIN_SCRIPT = 'Login Script';
    {$DEFINE A_LOGIN_TIME}
    Const A_LOGIN_TIME = 'Login Time';
    {$DEFINE A_LOW_RESET_TIME}
    Const A_LOW_RESET_TIME = 'Low Convergence Reset Time';
    {$DEFINE A_LOW_SYNC_INTERVAL}
    Const A_LOW_SYNC_INTERVAL = 'Low Convergence Sync Interval';
    {$DEFINE A_MAILBOX_ID}
    Const A_MAILBOX_ID = 'Mailbox ID';
    {$DEFINE A_MAILBOX_LOCATION}
    Const A_MAILBOX_LOCATION = 'Mailbox Location';
    {$DEFINE A_MEMBER}
    Const A_MEMBER = 'Member';
    {$DEFINE A_MEMORY}
    Const A_MEMORY = 'Memory';
    {$DEFINE A_MESSAGE_SERVER}
    Const A_MESSAGE_SERVER = 'Message Server';
    {$DEFINE A_MESSAGE_ROUTING_GROUP}
    Const A_MESSAGE_ROUTING_GROUP = 'Message Routing Group';
    {$DEFINE A_MESSAGING_DATABASE_LOCATION}
    Const A_MESSAGING_DATABASE_LOCATION = 'Messaging Database Location';
    {$DEFINE A_MESSAGING_ROUTING_GROUP}
    Const A_MESSAGING_ROUTING_GROUP = 'Messaging Routing Group';
    {$DEFINE A_MESSAGING_SERVER}
    Const A_MESSAGING_SERVER = 'Messaging Server';
    {$DEFINE A_MESSAGING_SERVER_TYPE}
    Const A_MESSAGING_SERVER_TYPE = 'Messaging Server Type';
    {$DEFINE A_MINIMUM_ACCOUNT_BALANCE}
    Const A_MINIMUM_ACCOUNT_BALANCE = 'Minimum Account Balance';
    {$DEFINE A_NETWORK_ADDRESS}
    Const A_NETWORK_ADDRESS = 'Network Address';
    {$DEFINE A_NETWORK_ADDRESS_RESTRICTION}
    Const A_NETWORK_ADDRESS_RESTRICTION = 'Network Address Restriction';
    {$DEFINE A_NNS_DOMAIN}
    Const A_NNS_DOMAIN = 'NNS Domain';
    {$DEFINE A_NOTIFY}
    Const A_NOTIFY = 'Notify';
    {$DEFINE A_OBITUARY}
    Const A_OBITUARY = 'Obituary';
    {$DEFINE A_ORGANIZATION_NAME}
    Const A_ORGANIZATION_NAME = 'O';
    {$DEFINE A_OBJECT_CLASS}
    Const A_OBJECT_CLASS = 'Object Class';
    {$DEFINE A_OPERATOR}
    Const A_OPERATOR = 'Operator';
    {$DEFINE A_ORGANIZATIONAL_UNIT_NAME}
    Const A_ORGANIZATIONAL_UNIT_NAME = 'OU';
    {$DEFINE A_OWNER}
    Const A_OWNER = 'Owner';
    {$DEFINE A_PAGE_DESCRIPTION_LANGUAGE}
    Const A_PAGE_DESCRIPTION_LANGUAGE = 'Page Description Language';
    {$DEFINE A_PARTITION_CONTROL}
    Const A_PARTITION_CONTROL = 'Partition Control';
    {$DEFINE A_PARTITION_CREATION_TIME}
    Const A_PARTITION_CREATION_TIME = 'Partition Creation Time';
    {$DEFINE A_PARTITION_STATUS}
    Const A_PARTITION_STATUS = 'Partition Status';
    {$DEFINE A_PASSWORD_ALLOW_CHANGE}
    Const A_PASSWORD_ALLOW_CHANGE = 'Password Allow Change';
    {$DEFINE A_PASSWORD_EXPIRATION_INTERVAL}
    Const A_PASSWORD_EXPIRATION_INTERVAL = 'Password Expiration Interval';
    {$DEFINE A_PASSWORD_EXPIRATION_TIME}
    Const A_PASSWORD_EXPIRATION_TIME = 'Password Expiration Time';
    {$DEFINE A_PASSWORD_MINIMUM_LENGTH}
    Const A_PASSWORD_MINIMUM_LENGTH = 'Password Minimum Length';
    {$DEFINE A_PASSWORD_REQUIRED}
    Const A_PASSWORD_REQUIRED = 'Password Required';
    {$DEFINE A_PASSWORD_UNIQUE_REQUIRED}
    Const A_PASSWORD_UNIQUE_REQUIRED = 'Password Unique Required';
    {$DEFINE A_PASSWORDS_USED}
    Const A_PASSWORDS_USED = 'Passwords Used';
    {$DEFINE A_PATH}
    Const A_PATH = 'Path';
    {$DEFINE A_PERMANENT_CONFIG_PARMS}
    Const A_PERMANENT_CONFIG_PARMS = 'Permanent Config Parms';
    {$DEFINE A_PHYSICAL_DELIVERY_OFFICE_NAME}
    Const A_PHYSICAL_DELIVERY_OFFICE_NAME = 'Physical Delivery Office Name';
    {$DEFINE A_POSTAL_ADDRESS}
    Const A_POSTAL_ADDRESS = 'Postal Address';
    {$DEFINE A_POSTAL_CODE}
    Const A_POSTAL_CODE = 'Postal Code';
    {$DEFINE A_POSTAL_OFFICE_BOX}
    Const A_POSTAL_OFFICE_BOX = 'Postal Office Box';
    {$DEFINE A_POSTMASTER}
    Const A_POSTMASTER = 'Postmaster';
    {$DEFINE A_PRINT_SERVER}
    Const A_PRINT_SERVER = 'Print Server';
    {$DEFINE A_PRIVATE_KEY}
    Const A_PRIVATE_KEY = 'Private Key';
    {$DEFINE A_PRINTER}
    Const A_PRINTER = 'Printer';
    {$DEFINE A_PRINTER_CONFIGURATION}
    Const A_PRINTER_CONFIGURATION = 'Printer Configuration';
    {$DEFINE A_PRINTER_CONTROL}
    Const A_PRINTER_CONTROL = 'Printer Control';
    {$DEFINE A_PRINT_JOB_CONFIGURATION}
    Const A_PRINT_JOB_CONFIGURATION = 'Print Job Configuration';
    {$DEFINE A_PROFILE}
    Const A_PROFILE = 'Profile';
    {$DEFINE A_PROFILE_MEMBERSHIP}
    Const A_PROFILE_MEMBERSHIP = 'Profile Membership';
    {$DEFINE A_PUBLIC_KEY}
    Const A_PUBLIC_KEY = 'Public Key';
    {$DEFINE A_QUEUE}
    Const A_QUEUE = 'Queue';
    {$DEFINE A_QUEUE_DIRECTORY}
    Const A_QUEUE_DIRECTORY = 'Queue Directory';
    {$DEFINE A_RECEIVED_UP_TO}
    Const A_RECEIVED_UP_TO = 'Received Up To';
    {$DEFINE A_REFERENCE}
    Const A_REFERENCE = 'Reference';
    {$DEFINE A_REPLICA}
    Const A_REPLICA = 'Replica';
    {$DEFINE A_REPLICA_UP_TO}
    Const A_REPLICA_UP_TO = 'Replica Up To';
    {$DEFINE A_RESOURCE}
    Const A_RESOURCE = 'Resource';
    {$DEFINE A_REVISION}
    Const A_REVISION = 'Revision';
    {$DEFINE A_ROLE_OCCUPANT}
    Const A_ROLE_OCCUPANT = 'Role Occupant';
    {$DEFINE A_STATE_OR_PROVINCE_NAME}
    Const A_STATE_OR_PROVINCE_NAME = 'S';
    {$DEFINE A_STREET_ADDRESS}
    Const A_STREET_ADDRESS = 'SA';
    {$DEFINE A_SAP_NAME}
    Const A_SAP_NAME = 'SAP Name';
    {$DEFINE A_SECURITY_EQUALS}
    Const A_SECURITY_EQUALS = 'Security Equals';
    {$DEFINE A_SECURITY_FLAGS}
    Const A_SECURITY_FLAGS = 'Security Flags';
    {$DEFINE A_SEE_ALSO}
    Const A_SEE_ALSO = 'See Also';
    {$DEFINE A_SERIAL_NUMBER}
    Const A_SERIAL_NUMBER = 'Serial Number';
    {$DEFINE A_SERVER}
    Const A_SERVER = 'Server';
    {$DEFINE A_SERVER_HOLDS}
    Const A_SERVER_HOLDS = 'Server Holds';
    {$DEFINE A_STATUS}
    Const A_STATUS = 'Status';
    {$DEFINE A_SUPPORTED_CONNECTIONS}
    Const A_SUPPORTED_CONNECTIONS = 'Supported Connections';
    {$DEFINE A_SUPPORTED_GATEWAY}
    Const A_SUPPORTED_GATEWAY = 'Supported Gateway';
    {$DEFINE A_SUPPORTED_SERVICES}
    Const A_SUPPORTED_SERVICES = 'Supported Services';
    {$DEFINE A_SUPPORTED_TYPEFACES}
    Const A_SUPPORTED_TYPEFACES = 'Supported Typefaces';
    {$DEFINE A_SURNAME}
    Const A_SURNAME = 'Surname';
    {$DEFINE A_IN_SYNC_UP_TO}
    Const A_IN_SYNC_UP_TO = 'Synchronized Up To';
    {$DEFINE A_TELEPHONE_NUMBER}
    Const A_TELEPHONE_NUMBER = 'Telephone Number';
    {$DEFINE A_TITLE}
    Const A_TITLE = 'Title';
    {$DEFINE A_TYPE_CREATOR_MAP}
    Const A_TYPE_CREATOR_MAP = 'Type Creator Map';
    {$DEFINE A_UID}
    Const A_UID = 'UID';
    {$DEFINE A_UNKNOWN}
    Const A_UNKNOWN = 'Unknown';
    {$DEFINE A_UNKNOWN_BASE_CLASS}
    Const A_UNKNOWN_BASE_CLASS = 'Unknown Base Class';
    {$DEFINE A_USER}
    Const A_USER = 'User';
    {$DEFINE A_VERSION}
    Const A_VERSION = 'Version';
    {$DEFINE A_VOLUME}
    Const A_VOLUME = 'Volume';
{$ENDIF}

