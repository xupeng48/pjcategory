//
//  UIColor+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 Create UIColor with a hex string.
 Example: UIColorHex(0xF0F), UIColorHex(66ccff), UIColorHex(#66CCFF88)
 
 Valid format: #RGB #RGBA #RRGGBB #RRGGBBAA 0xRGB ...
 The `#` or "0x" sign is not required.
 */
#ifndef UIColorHex
#define UIColorHex(_hex_)   [UIColor colorWithHexString:((__bridge NSString *)CFSTR(#_hex_))]
#endif

@interface UIColor (PJCategory)

#pragma mark - Create a UIColor Object

/**
 以16进制字符串创建RGB颜色，比如0x66ccff
 */
+ (UIColor *)colorWithRGB:(uint32_t)rgbValue;

/**
 以16进制字符串创建RGBA颜色，比如0x66ccffff
 */
+ (UIColor *)colorWithRGBA:(uint32_t)rgbaValue;

/**
 创建RGBA颜色

 @param rgbValue  rgb的值，比如0x66CCFF.
 
 @param alpha    透明度，从0.0到1.0
 
 */
+ (UIColor *)colorWithRGB:(uint32_t)rgbValue alpha:(CGFloat)alpha;

/**
 由16进制字符串创建RGBA颜色
 
 @discussion:
 支持: #RGB #RGBA #RRGGBB #RRGGBBAA 0xRGB ...
 #和0x并不是必须的
 如果没有alpha通道，默认是alpha是1.0

 举例: @"0xF0F", @"66ccff", @"#66CCFF88"
 */
+ (nullable UIColor *)colorWithHexString:(NSString *)hexStr;

/**
 两个颜色混合出一个新颜色
 */
- (UIColor *)colorByAddColor:(UIColor *)add blendMode:(CGBlendMode)blendMode;



#pragma mark - Get color's description

/**
 以16进制整数返回，不包含alpha通道
 比如0x66ccff
 */
- (uint32_t)rgbValue;

/**
 以16进制整数返回，包含alpha通道
 比如0x66ccffff
 */
- (uint32_t)rgbaValue;

/**
 以16进制字符串(小写)返回
 比如@"0066cc"
 
 如果颜色空间不是RGB，那么会返回nil
 */
- (nullable NSString *)hexString;

/**
 以16进制字符串(小写)返回
 比如@"0066ccff"
 
 如果颜色空间不是RGBA，那么会返回nil
 */
- (nullable NSString *)hexStringWithAlpha;


#pragma mark - Retrieving Color Information

/**
 RGB颜色空间中的red
 */
@property (nonatomic, readonly) CGFloat red;

/**
 RGB颜色空间中的green
 */
@property (nonatomic, readonly) CGFloat green;

/**
 RGB颜色空间中的blue
 */
@property (nonatomic, readonly) CGFloat blue;
/**
 HSB颜色空间中的hue
 */
@property (nonatomic, readonly) CGFloat hue;

/**
 HSB颜色空间中的saturation
 */
@property (nonatomic, readonly) CGFloat saturation;

/**
 HSB颜色空间中的brightness
 */
@property (nonatomic, readonly) CGFloat brightness;

/**
 alpha通道
 */
@property (nonatomic, readonly) CGFloat alpha;

/**
 颜色空间
 */
@property (nonatomic, readonly) CGColorSpaceModel colorSpaceModel;

/**
 颜色空间的字符串描述
 */
@property (nullable, nonatomic, readonly) NSString *colorSpaceString;

@end

NS_ASSUME_NONNULL_END
