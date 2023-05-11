//
//  PhoneConstant.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 04/11/15.
//  Copyright (c) 2015 Phone.Com. All rights reserved.
//

#ifndef MobileOffice_PhoneConstant_h
#define MobileOffice_PhoneConstant_h

#define k_SecAttrServiceKey @"com.phone.mobile.office"
#define k_keychainIdentifier @"phoneComKeyChainActiveUserData"

#define kPhoneActiveUser @"ActiveUserLogin"
#define kPhoneActiveUserSettings @"ActiveUserSettings"

#define kUserExtension @"Extension"
#define kUserMobileNumber @"MobileNumber"
#define kUserPhoneComNumber @"PhoneComNumber"

#define kCallType @"callType"
#define kCallTypeGateway @"callTypeGateway"
#define kCallTypeCallBack @"callTypeCallBack"
#define kCallTypeVoIP @"callTypeVoIP"

#define kCallTypeGatewayLabel @"Gateway"
#define kCallTypeCallBackLabel @"CallBack"
#define kCallTypeVoIPLabel @"VoIP"
#define kCallTypeLabel @"Call Type"

#define kCallerIdLabel @"Caller ID"
#define kInstantTransferLabel @"Instant Transfer"
#define kAdvanceSettingsLabel @"Advance Settings"
#define kSipOverTlsLabel @"Secure Connection(Tls)"
#define kSipMediaOverSrtpLabel @"Secure Voice(Srtp)"

#define kEnableDeviceLogs @"Enable Device Logs"
#define kEmailDeviceLogs  @"Email Device Logs"

#define kCallerIdMismatch @"Show caller ID mismatch alert"


#define kCallerAnalyticsLabel @"Caller Analytics"
#define kSpamAlertLabel @"Spam Alert"
#define kReversePhoneLabel @"Reverse Phone"

#define APP_NAME @"Phone.com"

#define kIsFirstLaunch @"isFirstLaunch"
#define kExtensionContactMigrated @"isExtensionContactMigrated"
#define kDeviceContactMigrated @"isDeviceContactMigrated"




#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0

#elif 

#define NSLocalizedString(key, comment)                                        \
  [[NSBundle mainBundle] localizedStringForKey:(key) value:@"" table:nil]

#endif

#define kLogInViewOptionsTitle @"Title"
#define KLogInViewOptionsPlaceHolder @"PlaceHolder"
#define KLogInViewSecureEntry @"isSecured"
#define KLogInViewKeyBoardType @"KeyBoardType"
#define kLogInViewOptionsValue @"value"

#define kRecentCallLimit 200
#define kRecentMessagesLimit 1000
#define kVoicemailLimitToFetchUnreadCount 1

#define kDataPersistanceExtensionContactDownloaded @"EXTCONTACTDOWNLOADED"
#define kDataPersistanceDeviceContactDownloaded @"DEVCONTACTDOWNLOADED"
#define kDataPersistanceContactOrdering @"CONTACTORDERING"

#define KContactsTabbarTitle @"Contacts"
#define KKeypadTabbarTitle @"Keypad"
#define KVoicemailTabbarTitle @"Voicemail"
#define KRecentsTabbarTitle @"Recents"
#define KFavoritesTabbarTitle @"Favorites"
#define KContactOrderingFirstName @"ContactOrderFirstName"
#define KContactOrderingLastName @"ContactOrderLastName"

#define KSecletedTabBar @"selectedTabbar"



#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
#define IS_IPHONE_X  (IS_IPHONE && SCREEN_MAX_LENGTH == 812.0)

#define kVoIPCallDescription                                                   \
  @"Call uses your wireless connection only. This mode is best suited if you " \
  @"have a good internet connection or limited mobile reception; for "         \
  @"example, when travelling."

#define kCallBackCallDescription                                               \
  @"Call includes an inbound call to your mobile and an outbound call to the " \
  @"destination number. This mode is best suited if you don't have a good "    \
  @"internet connection and you don't want to burn your local airtime "        \
  @"minutes."

#define kGateWayCallDescription                                                \
  @"Call uses your local airtime minutes. This mode is best suited if you "    \
  @"don't have a good internet connection."

#define UNKNOWN_SECTION_NAME @"~"

#define EMPTY_STRING @""
#define SPACE_STRING @" "
#define EMPTY_CONTACT_TYPE @"phone"

#define CONTACT_DETAILS_HEADER_FOOTER_HEIGHT 30.0

#define RIPPLE_EFFECT_RECT                                                     \
  CGRectMake(self.view.frame.size.width / 2, self.view.frame.size.width - 44,  \
             40, 40)

#define UNKNOWN_CALLER_ID @"Unknown"

#define SMS_SYNC_TIME @"KSmsSyncTime"
#define RECENT_CALL_SYNC_TIME @"KRecentCallSyncTime"

#define SMS_OUTBOUNT_SENDER_ID @"kSmsOutboundSenderId"
#define FAX_OUTBOUNT_SENDER_ID @"kFaxOutboundSenderId"
#define DEFAULT_EMAIL_CONFIRMATION @"kDefaultEmailConfirmation"
#define MESSAGE_SENDER_ID @"kMessageSenderId"

#define MESSAGE_SETTING_TEXTFIELD_CELL @"MessagesSettingsTextFieldIentifier"
#define MESSAGE_SETTING_RIGHT_DETAIL_CELL @"MessagesSettingsRightDetailIdentifier"
#define MESSAGE_SETTING_RIGHT_SWITCH_CELL @"MessageSettingsSwitchCellIdentifier"
#define MESSAGE_SETTING_TEXTFIELD_PLAIN_CELL @"MessagesSettingsTextFieldIentifierDeleteAllMessages"


#define CALL_SETTING_RIGHT_DETAIL_CELL @"CallSettingsRightDetailIdentifier"
#define CALL_SETTING_ENABLE_ADVANCE_SETTINGS @"kCallSettingEnableAdvanceSettings"
#define CALL_SETTING_SWITCH_CELL @"CallSettingsSwitchCellIdentifier"
#define CALL_SETTING_SPAM_ALERT_PREFERENCE @"kCallSettingSpamAlertPreference"
#define CALL_SETTING_REVERSE_PHONE_PREFERENCE @"kCallSettingReversePhonePreference"
#define CALL_SETTING_SIP_OVER_TLS_PREFERENCE @"kCallSettingSipOverTlsPreference"
#define CALL_SETTING_MEDIA_OVER_SRTP_PREFERENCE @"kCallSettingMediaOverSrtpPreference"
#define CALL_SETTING_ENABLE_DEVICE_LOGS @"kCallSettingEnableDeviceLogs"
#define CALL_SETTING_ENABLE_CALLER_ID_MISMATCH @"kCallSettingEnableCallerIdMismatch"
#define DONT_SHOW_CALLER_ID_MISMATCH @"kDontShowCallerIdMismatch"



#define ADVANCE_SETTING_RIGHT_TEXTFIELD_CELL @"AdvanceSettingsRightTextfieldIdentifier"
#define ADVANCE_SETTING_RIGHT_SEGMENT_CELL @"AdvanceSettingsSegmentCellIdentifier"
#define ADVANCE_SETTING_RIGHT_SWITCH_CELL @"AdvanceSettingsSwitchCellIdentifier"

#define INSTANT_TRANSFER_PLAIN_CELL @"InstantTransferPlainIdentifier"
#define INSTANT_TRANSFER_VALID_NUMBERALERT @"Number is not a valid number. Please try again with valid number."

#define ADVANCE_SETTING_USER_LABEL @"User"
#define ADVANCE_SETTING_PASSWORD_LABEL @"Password"
#define ADVANCE_SETTING_DOMAIN_LABEL @"Domain"
#define ADVANCE_SETTING_PROTOCOL_LABEL @"Protocol"
#define ADVANCE_SETTING_PORT_LABEL @"Port"
#define ADVANCE_SETTING_STUN_LABEL @"Stun"
#define ADVANCE_SETTING_ENABLE_IPV4_PROXY @"IPV4 Proxy"
#define ADVANCE_SETTING_ENABLE_IPV6_PROXY @"IPV6 Proxy"
#define ADVANCE_SETTING_IPV4_PROXY_SERVER @"IPV4 Proxy Server"
#define ADVANCE_SETTING_IPV6_PROXY_SERVER @"IPV6 Proxy Server"
#define ADVANCE_SETTING_SRTP @"SRTP"



#define ADVANCE_SETTING_USER_PLACE_HOLDER @"Please enter sip user."
#define ADVANCE_SETTING_PASSWORD_PLACE_HOLDER @"Please enter sip password."
#define ADVANCE_SETTING_DOMAIN_PLACE_HOLDER @"Please enter sip domain."
#define ADVANCE_SETTING_PORT_PLACE_HOLDER @"Please enter sip port."

#define ADVANCE_SETTING_ENABLE_ACCOUNT @"Enable Account"
#define ADVANCE_SETTING_ENABLE_ACCOUNT_KEY @"kAdvanceSettingsSipEnableAccount"


#define ADVANCE_SETTING_SIP_USER @"sipUser"
#define ADVANCE_SETTING_SIP_PASSWORD @"sipPassword"
#define ADVANCE_SETTING_SIP_DOMAIN @"sipDomain"
#define ADVANCE_SETTING_SIP_PROTOCOL @"sipProtocol"
#define ADVANCE_SETTING_SIP_PORT @"sipPort"
#define ADVANCE_SETTING_SIP_STUN @"sipStunServer"
#define ADVANCE_SETTING_SIP_PROTOCOL_STRING @"sipProtocolString"
#define ADVANCE_SETTING_SIP_IPV6_PROXY @"ipv6Proxy"
#define ADVANCE_SETTING_SIP_IPV4_PROXY @"ipv4Proxy"
#define ADVANCE_SETTING_SIP_IPV6_PROXY_ENABLED @"ipv6ProxyEnabled"
#define ADVANCE_SETTING_SIP_IPV4_PROXY_ENABLED @"ipv4ProxyEnabled"
#define ADVANCE_SETTING_SIP_SRTP_ENABLED @"srtpAdvanceSettingsEnabled"


#define CONTACTS_SETTINGS_PLAIN_CELL @"ContactsTransferPlainIdentifier"
#define CONTACTS_SETTINGS_CHOICE_CELL @"ContactsSettingsNameOrderIdentifier"

#define DEVICE_CONTACT_UPDATED @"kDeviceContactsUpdated"
#define EXTENSION_CONTACT_UPDATED @"kExtensionContactsUpdated"
#define ALL_CONTACT_UPDATED @"kAllContactUpdated"
#define FAVORITE_CONTACT_UPDATED @"kFavoriteContactsUpdated"
#define CONTACT_DELETED @"kContactsDeleted"
#define DEVICE_CONTACT_PERMISSION_DENIED @"kDeviceContactPermissionDenied"
#define CONTACT_ORDERING_UPDATED @"kContactOrderingUpdated"
#define CONTACTS_UPDATED @"kCONTACTS_UPDATED"
#define CONTACTS_UPDATE_FAILED @"kCONTACTS_UPDATE_FAILED"

#define FAX_SETTINGS_TITLE @"Fax"
#define CALL_SETTINGS_TITLE @"Call"
#define MESSAGE_SETTINGS_TITLE @"Message"
#define FAQS_SETTINGS_TITLE @"FAQS"
#define ABOUT_SETTINGS_TITLE @"About"
#define CONTACTS_SETTINGS_TITLE @"Contacts"
#define NOTIFICATION_SETTINGS_TITLE @"Notifications"

#define RESET_ALL_MESSAGES @"Reset Messages"
#define RESET_ALL_MESSAGES_TITLE @"Reset Messages"



#define DEVICE_SYNC_SETTINGS_TITLE @"Sync Device Contact"
#define EXTENSION_SYNC_SETTINGS_TITLE @"Sync Extension Contact"
#define CONTACT_SETTING_FIRST_NAME_ORDER_TITLE @"First Name"
#define CONTACT_SETTING_LAST_NAME_ORDER_TITLE @"Last Name"

#define INCOMING_MESSAGE_SETTINGS_TITLE @"Incoming Messages"

#define PUSH_NOTIFICATION_VALUE @"messageNotify"


#define DEVICE_CONTACT_SYNC_PROGRESS_MESSAGE @"Device contacts syncying in progress please retry after sometime."
#define EXTENSION_CONTACT_SYNC_PROGRESS_MESSAGE @"Extension contacts syncying in progress please retry after sometime."

#define kCONVERSATION_STATUS_SUCCESS @"success"

typedef enum {
  ContactsTypePhoneCom,
  ContactsTypeDevice

} ContactsType;

typedef enum {
  RecordTypePhone,
  RecordTypeEmail,
  RecordTypeImage

} RecordType;

typedef enum {
  ActionSheetTypeSendMessage,
  ActionSheetTypeAddToFavorite,
  ActionSheetTypeBlockCaller,
   ActionSheetTypeCallNumber

} ActionSheetType;

typedef enum {
  PlayerStatusStopped,
  PlayerStatusPlaying,
  PlayerStatusPause,
  PlayerStatusWaiting,
  PlayerStatusFinished

} PlayerStatus;

typedef NS_ENUM(NSInteger, CallSettingSpamAlertPrefernce) {
    CallSettingSpamAlertPreferncOff = 0,
    CallSettingSpamAlertPrefernceOn = 1
};

typedef NS_ENUM(NSInteger, CallSettingReversePhonePrefernce) {
    CallSettingReversePhonePrefernceOff = 0,
    CallSettingReversePhonePrefernceOn = 1
};

typedef NS_ENUM(NSInteger, IsFirstLaunch) {
    IsFirstLaunchYes = 0,
    IsFirstLaunchNo = 1
};

#endif
