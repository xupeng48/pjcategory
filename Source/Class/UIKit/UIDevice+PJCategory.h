//
//  UIDevice+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define OS_STATUS_BAR_HEIGHT [UIDevice systemStatusBarHeight]

@interface UIDevice (PJCategory)

/**
 设备状态栏高度(iPhoneX 44.0，其他20.0)
 */
+ (CGFloat)systemStatusBarHeight;

/**
 iPhoneX需要在View底部增加的额外的距离
 */
+ (CGFloat)iPhoneXTabbarAdditionalHeightOrNone;

/**
 是否是iPhonex
 */
+ (BOOL)isiPhoneXSeries;

#pragma mark - Device Information

/// 系统版本
+ (double)systemVersion;

/// 是否是iPad
@property (nonatomic, readonly) BOOL isPad;

/// 是否是模拟器
@property (nonatomic, readonly) BOOL isSimulator;

/// 是否越狱
@property (nonatomic, readonly) BOOL isJailbroken;

/// 是否可以打电话
@property (nonatomic, readonly) BOOL canMakePhoneCalls NS_EXTENSION_UNAVAILABLE_IOS("");

/// 设备型号 例如："iPhone6,1"
/// @see http://theiphonewiki.com/wiki/Models
@property (nullable, nonatomic, readonly) NSString *machineModel;

/// 设备名称 例如："iPhone 5s"
/// @see http://theiphonewiki.com/wiki/Models
@property (nullable, nonatomic, readonly) NSString *machineModelName;

/// 系统开机时间
@property (nonatomic, readonly) NSDate *systemUptime;


#pragma mark - Network Information

/// WIFI IP 地址，例如：@"192.168.1.111"
@property (nullable, nonatomic, readonly) NSString *ipAddressWIFI;

/// 蜂窝移动 IP地址，例如：@"10.2.2.222"
@property (nullable, nonatomic, readonly) NSString *ipAddressCell;


/**
 网络流量类型
 
 WWAN: Wireless Wide Area Network.
 For example: 3G/4G.
 
 WIFI: Wi-Fi.
 
 AWDL: Apple Wireless Direct Link (peer-to-peer connection).
 For exmaple: AirDrop, AirPlay, GameKit.
 */
typedef NS_OPTIONS(NSUInteger, PJNetworkTrafficType) {
    PJNetworkTrafficTypeWWANSent     = 1 << 0,
    PJNetworkTrafficTypeWWANReceived = 1 << 1,
    PJNetworkTrafficTypeWIFISent     = 1 << 2,
    PJNetworkTrafficTypeWIFIReceived = 1 << 3,
    PJNetworkTrafficTypeAWDLSent     = 1 << 4,
    PJNetworkTrafficTypeAWDLReceived = 1 << 5,
    
    PJNetworkTrafficTypeWWAN = PJNetworkTrafficTypeWWANSent | PJNetworkTrafficTypeWWANReceived,
    PJNetworkTrafficTypeWIFI = PJNetworkTrafficTypeWIFISent | PJNetworkTrafficTypeWIFIReceived,
    PJNetworkTrafficTypeAWDL = PJNetworkTrafficTypeAWDLSent | PJNetworkTrafficTypeAWDLReceived,
    
    PJNetworkTrafficTypeALL = PJNetworkTrafficTypeWWAN |
    PJNetworkTrafficTypeWIFI |
    PJNetworkTrafficTypeAWDL,
};

/**
 获取设备的网络流量
 
 @discussion 统计到的是从设备上次重启后.
 Usage:
 
 uint64_t bytes = [[UIDevice currentDevice] getNetworkTrafficBytes:PJNetworkTrafficTypeALL];
 NSTimeInterval time = CACurrentMediaTime();
 
 uint64_t bytesPerSecond = (bytes - _lastBytes) / (time - _lastTime);
 
 _lastBytes = bytes;
 _lastTime = time;
 */
- (uint64_t)getNetworkTrafficBytes:(PJNetworkTrafficType)types;

#pragma mark - Disk Space

// 全部的磁盘空间，出错返回-1
@property (nonatomic, readonly) int64_t diskSpace;

/// 可用的磁盘空间，出错返回-1
@property (nonatomic, readonly) int64_t diskSpaceFree;

/// 已用的磁盘空间，出错返回-1
@property (nonatomic, readonly) int64_t diskSpaceUsed;

#pragma mark - Memory Information

/// 一共的物理内存，单位byte，出错返回-1
@property (nonatomic, readonly) int64_t memoryTotal;

/// 已用的内存，单位byte (active + inactive + wired) 出错返回-1
@property (nonatomic, readonly) int64_t memoryUsed;

/// 可用的内存，单位byte，出错返回-1
@property (nonatomic, readonly) int64_t memoryFree;

/// Acvite内存，单位byte，出错返回-1
@property (nonatomic, readonly) int64_t memoryActive;

/// Inactive内存，单位byte，出错返回-1
@property (nonatomic, readonly) int64_t memoryInactive;

// Wired内存，单位byte，出错返回-1
@property (nonatomic, readonly) int64_t memoryWired;

// Purgable内存，单位byte，出错返回-1
@property (nonatomic, readonly) int64_t memoryPurgable;

#pragma mark - CPU Information

// CPU核数
@property (nonatomic, readonly) NSUInteger cpuCount;

// 当前的CPU使用情况，1表示100%，出错返回-1
@property (nonatomic, readonly) float cpuUsage;

// 每个CPU的核使用百分比
@property (nullable, nonatomic, readonly) NSArray<NSNumber *> *cpuUsagePerProcessor;

@end

NS_ASSUME_NONNULL_END

