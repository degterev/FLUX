//
//  TEBaseStore.h
//  MasterApp
//
//  Created by Alexey Fayzullov on 9/9/15.
//  Copyright (c) 2015 Techery. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TEDomainMiddleware;

@interface TEBaseStore <StateType> : NSObject

typedef StateType (^TEActionCallback)(id action);

@property (nonatomic, readonly) StateType state;
@property (nonatomic, assign) BOOL isLoaded;

- (void)onAction:(Class)actionClass callback:(TEActionCallback)callback;
- (BOOL)respondsToAction:(id)action;

- (void)dispatchAction:(id)action;

- (StateType)defaultState __attribute__((deprecated));
+ (StateType)defaultState;

@end
