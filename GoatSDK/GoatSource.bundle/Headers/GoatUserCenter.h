//
//  GoatUserCenter.h
//  GoatUserCenter
//
//  Created by choici o on 2021/1/5.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, UserCenterEnvironment) {
    UserCenterEnvironmentDevelop = 1,
    UserCenterEnvironmentPreparation,
    UserCenterEnvironmentRelease,
};

typedef void(^GoatCompletionHandler)(int code, id _Nullable response);

//! Project version number for GoatUserCenter.
FOUNDATION_EXPORT double GoatUserCenterVersionNumber;

//! Project version string for GoatUserCenter.
FOUNDATION_EXPORT const unsigned char GoatUserCenterVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GoatUserCenter/PublicHeader.h>


@protocol GoatUserCenterDelegate <NSObject>

- (void)purchaseOrderReplace;

@end


@interface GoatUserCenter : NSObject

@property (copy, nonatomic) NSString * _Nullable whatsType;
@property (strong, nonatomic) NSMutableDictionary * _Nullable whereGoatInfo;
@property (assign, nonatomic) UserCenterEnvironment userCenterEnvironment;//正式环境
@property (weak, nonatomic)id<GoatUserCenterDelegate> _Nullable delegate;


+ (GoatUserCenter *_Nonnull)usercenter;

- (void)setOrientation:(NSString *_Nonnull)oriert;

- (BOOL)vertical;

- (void)enterUserCenterWithViewController:(UIViewController * _Nonnull)viewController userInfo:(NSMutableDictionary *_Nonnull)userInfo loginComplectionHandler:(GoatCompletionHandler _Nullable)loginHandler logoutComplectionHandler:(GoatCompletionHandler _Nullable)logoutHandler;

- (void)loginUserCenterWithViewController:(UIViewController *_Nonnull)viewController loginComplectionHandler:(GoatCompletionHandler _Nullable )loginHandler;

- (void)usercenterUpdateDatasWithQuery:(NSDictionary *_Nullable)query response:(NSDictionary *_Nullable)response errcode:(int)code noSaved:(BOOL)noSaved;

- (void)loginSuccessUpdateQuery:(NSDictionary *_Nullable)query response:(NSDictionary *_Nonnull)response noSaved:(BOOL)noSaved;



@end



