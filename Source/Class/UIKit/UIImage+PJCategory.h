//
//  UIImage+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (PJCategory)

/**
 适配iPhone和iPad的图
 */
+ (nullable UIImage *)pj_imageNamed:(NSString *)name ipadNamed:(NSString *)ipadName;

/**
 根据颜色创建一个1x1的图
 */
+ (nullable UIImage *)imageWithColor:(UIColor *)color;

/**
 根据颜色创建一个指定大小的图
 */
+ (nullable UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 用当前图片作为mask，生成一个单一颜色的图片
 */
- (UIImage *)imageByMaskColor:(UIColor *)color;

/**
 是否有alpha通道
 */
- (BOOL)hasAlphaChannel;

/**
 图片按尺寸进行放大缩小
 */
- (nullable UIImage *)imageByResizeToSize:(CGSize)size;

/**
 图片按比例进行放大缩小
 */
- (nullable UIImage *)imageByResizeWithScale:(CGFloat)scale;

/**
 图片按尺寸进行放大缩小

 @param size        目标大小
 @param contentMode contentMode
 @return The new image with the given size.
 */
- (nullable UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

/**
 由当前图片的一部分裁剪成一张新的图
 
 @param rect  图片内部的Rect
 */
- (nullable UIImage *)imageByCropToRect:(CGRect)rect;

/**
 根据圆角裁剪图片
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius;


/**
根据圆角裁剪图片
 
 @param radius       圆角
 @param borderWidth  边框宽度
 @param borderColor 边框颜色
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor;

/**
 根据圆角裁剪图片
 
 @param radius       圆角
 @param borderWidth  边框宽度
 @param borderColor 边框颜色
 @param borderLineJoin 边框的join模式
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                       corners:(UIRectCorner)corners
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor
                                borderLineJoin:(CGLineJoin)borderLineJoin;

/**
 图片添加Light blur
 */
- (UIImage *)applyLightEffect;

/**
 图片添加ExtraLight blur
 */
- (UIImage *)applyExtraLightEffect;

/**
 图片添加Dark blur
 */
- (UIImage *)applyDarkEffect;

/**
 图片添加Tint Color
 */
- (UIImage *)applyTintEffectWithColor:(UIColor *)tintColor;

/**
 图片添加blur
 */
- (nullable UIImage *)applyBlurWithRadius:(CGFloat)blurRadius tintColor:(nullable UIColor *)tintColor saturationDeltaFactor:(CGFloat)saturationDeltaFactor maskImage:(nullable UIImage *)maskImage;

@end

NS_ASSUME_NONNULL_END
