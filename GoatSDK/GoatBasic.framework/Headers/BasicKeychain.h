//
//  GTKeychain.h
//  GTSDK
//
//  Created by choici on 2019/4/29.
//  Copyright © 2019 Goat Games. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BasicKeychainItem;

NSString * _Nullable BasicGrepBundleSeedId(void);

NS_ASSUME_NONNULL_BEGIN

@interface BasicKeychain : NSObject

/**
 获取keyChain密文
 
 @discussion    通过指定服务、账号查找对应密文
 
 @param serviceName 对应BasicKeychainItem中的service
 @param account     对应BasicKeychainItem中的account
 
 @return 密文或nil
 */
+ (NSString *)bc_getPasswordForService:(NSString *)serviceName
                            account:(NSString *)account
                              error:(__autoreleasing NSError **)error;

/**
 删除keyChain密文
 
 @discussion    通过指定服务、账号删除对应密文
 
 @param serviceName 对应BasicKeychainItem中的service
 @param account     对应BasicKeychainItem中的account
 */
+ (BOOL)bc_deletePasswordForService:(NSString *)serviceName
                         account:(NSString *)account
                           error:(__autoreleasing NSError **)error;

/**
 设置keyChain密文
 
 @discussion    将密文设置到指定服务的账号下
 
 @param serviceName 对应BasicKeychainItem中的service
 @param account     对应BasicKeychainItem中的account
 */
+ (BOOL)bc_setPassword:(NSString *)password
         forService:(NSString *)serviceName
            account:(NSString *)account
              error:(__autoreleasing NSError **)error;

/**
 插入item到keyChain
 */
+ (BOOL)bc_insertItem:(BasicKeychainItem *)item error:(__autoreleasing NSError **)error;
/**
 更新keyChain中的item
 */
+ (BOOL)bc_updateItem:(BasicKeychainItem *)item error:(__autoreleasing NSError **)error;
/**
 从keyChain删除item
 */
+ (BOOL)bc_deleteItem:(BasicKeychainItem *)item error:(__autoreleasing NSError **)error;

/**
 Find an item from keychain.
 
 @discussion The service,account is optinal. It returns only one item if there
 exist multi.
 
 @param item  The item for query.
 
 @param error On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `GoatKeychainErrorCode`.
 
 @return An item or nil.
 */
+ (BasicKeychainItem *)bc_selectOneItem:(BasicKeychainItem *)item error:(__autoreleasing NSError **)error;
/**
 查询符合某item的keychain中的密文，并设置到item的密文字段上
 */
+ (void)bc_selectSecValueToItem:(BasicKeychainItem *)item error:(__autoreleasing NSError **)error;
/**
 查询符合某item的keychain中的所有item
 */
+ (NSArray *)bc_selectItems:(BasicKeychainItem *)item error:(__autoreleasing NSError **)error;
/**
 获取证书中包含开发者团队Id的KeychainGroup
 */
+ (NSString *)bc_getAccessGroup;

@end




/**
 Error code in GoatKeychain API.
 */
typedef NS_ENUM (NSUInteger, BasicKeychainErrorCode) {
    BasicKeychainErrorUnimplemented = 1, ///< Function or operation not implemented.
    BasicKeychainErrorIO, ///< I/O error (bummers)
    BasicKeychainErrorOpWr, ///< File already open with with write permission.
    BasicKeychainErrorParam, ///< One or more parameters passed to a function where not valid.
    BasicKeychainErrorAllocate, ///< Failed to allocate memory.
    BasicKeychainErrorUserCancelled, ///< User cancelled the operation.
    BasicKeychainErrorBadReq, ///< Bad parameter or invalid state for operation.
    BasicKeychainErrorInternalComponent, ///< Internal...
    BasicKeychainErrorNotAvailable, ///< No keychain is available. You may need to restart your computer.
    BasicKeychainErrorDuplicateItem, ///< The specified item already exists in the keychain.
    BasicKeychainErrorItemNotFound, ///< The specified item could not be found in the keychain.
    BasicKeychainErrorInteractionNotAllowed, ///< User interaction is not allowed.
    BasicKeychainErrorDecode, ///< Unable to decode the provided data.
    BasicKeychainErrorAuthFailed, ///< The user name or passphrase you entered is not.
};

/**
 When query to return the item's data, the error
 errSecInteractionNotAllowed will be returned if the item's data is not
 available until a device unlock occurs.
 */
typedef NS_ENUM (NSUInteger, BasicKeychainAccessible) {
    BasicKeychainAccessibleNone = 0,
    BasicKeychainAccessibleWhenUnlocked,
    BasicKeychainAccessibleAfterFirstUnlock,
    BasicKeychainAccessibleAlways,
    BasicKeychainAccessibleWhenPasscodeSetThisDeviceOnly,
    BasicKeychainAccessibleWhenUnlockedThisDeviceOnly,
    BasicKeychainAccessibleAfterFirstUnlockThisDeviceOnly,
    BasicKeychainAccessibleAlwaysThisDeviceOnly,
};

/**
 Whether the item in question can be synchronized.
 */
typedef NS_ENUM (NSUInteger, BasicKeychainQuerySynchronizationMode) {
    BasicKeychainQuerySynchronizationModeAny = 0,
    BasicKeychainQuerySynchronizationModeNo,
    BasicKeychainQuerySynchronizationModeYes,
};

@interface BasicKeychainItem : NSObject <NSCopying>

@property (nonatomic, copy) NSString *service; ///< kSecAttrService
@property (nonatomic, copy) NSString *account; ///< kSecAttrAccount
@property (nonatomic, copy) NSString *generic; ///< kSecAttrGeneric
@property (nonatomic, copy) NSData *passwordData; ///< kSecValueData
@property (nonatomic, copy) NSString *password; ///< shortcut for `passwordData`
@property (nonatomic, copy) id <NSCoding> passwordObject; ///< shortcut for `passwordData`

@property (nonatomic, copy) NSString *label; ///< kSecAttrLabel
@property (nonatomic, copy) NSNumber *type; ///< kSecAttrType (FourCC)
@property (nonatomic, copy) NSNumber *creater; ///< kSecAttrCreator (FourCC)
@property (nonatomic, copy) NSString *comment; ///< kSecAttrComment
@property (nonatomic, copy) NSString *descr; ///< kSecAttrDescription
@property (nonatomic, readonly, copy) NSDate *modificationDate; ///< kSecAttrModificationDate
@property (nonatomic, readonly, copy) NSDate *creationDate; ///< kSecAttrCreationDate
@property (nonatomic, copy) NSString *accessGroup; ///< kSecAttrAccessGroup

@property (nonatomic, assign) BasicKeychainAccessible accessible; ///< kSecAttrAccessible
@property (nonatomic, assign) BasicKeychainQuerySynchronizationMode synchronizable;

@end


NS_ASSUME_NONNULL_END
