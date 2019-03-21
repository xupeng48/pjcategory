//
//  UIScreen+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScreen (PJCategory)

/**
 Main Screen的scale
 */
+ (CGFloat)screenScale;

/**
 当前的屏幕orientation的bounds
 */
- (CGRect)currentBounds NS_EXTENSION_UNAVAILABLE_IOS("");

/**
 指定方向的bounds
 */
- (CGRect)boundsForOrientation:(UIInterfaceOrientation)orientation;

/**
 屏幕像素尺寸
 */
@property (nonatomic, readonly) CGSize sizeInPixel;

/**
 PPI
 */
@property (nonatomic, readonly) CGFloat pixelsPerInch;

@end

NS_ASSUME_NONNULL_END
