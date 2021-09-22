//
//  IdSelectorCall
//
//  Created by choici on 19/12/25.
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSObject (BasicMsgSend)

+ (id)bc_callSelector:(SEL)selector error:(NSError *__autoreleasing *)error,...;

+ (id)bc_callSelectorName:(NSString *)selName error:(NSError *__autoreleasing *)error,...;

- (id)bc_callSelector:(SEL)selector error:(NSError *__autoreleasing *)error,...;

- (id)bc_callSelectorName:(NSString *)selName error:(NSError *__autoreleasing *)error,...;


@end

@interface NSString (BasicMsgSend)

- (id)bc_callClassSelector:(SEL)selector error:(NSError *__autoreleasing *)error,...;

- (id)bc_callClassSelectorName:(NSString *)selName error:(NSError *__autoreleasing *)error,...;

- (id)bc_callClassAllocInitSelector:(SEL)selector error:(NSError *__autoreleasing *)error,...;

- (id)bc_callClassAllocInitSelectorName:(NSString *)selName error:(NSError *__autoreleasing *)error,...;

@end
