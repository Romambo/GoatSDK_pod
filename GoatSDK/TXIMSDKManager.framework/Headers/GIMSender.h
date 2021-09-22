//
//  GIMSender.h
//  TXIMSDKManager
//
//  Created by Adminstration on 2021/6/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GIMSender : NSObject

@property(nonatomic,copy) NSString* server_id;
@property(nonatomic,copy) NSString* user_id;
// app_id传bunble id,  [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleIdentifier"]
@property(nonatomic,copy) NSString* app_id;
@property(nonatomic,copy) NSString* game_id;
@property(nonatomic,copy) NSString* from_role_id;
@property(nonatomic,copy) NSString* from_role_nickname;


@end

NS_ASSUME_NONNULL_END
