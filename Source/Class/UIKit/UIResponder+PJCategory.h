//
//  UIResponder+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIResponder(PJCategory)

/**
 在当前响应者的响应链中寻找符合class最近的响应target
 */
- (nullable __kindof UIResponder *)pj_findClosetResponderInResponderChainWith:(Class)objClass;

/**
 基于上面👆方法，获取承载的ViewController
 */
- (nullable __kindof UIViewController *)pj_findClosetControllerInResponderChain;

@end

NS_ASSUME_NONNULL_END
