//
//  UIApplication+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (PJCategory)


// sandbox中document目录
@property (nonatomic, readonly) NSURL *documentsURL;
@property (nonatomic, readonly) NSString *documentsPath;

// sandbox中caches目录
@property (nonatomic, readonly) NSURL *cachesURL;
@property (nonatomic, readonly) NSString *cachesPath;

// sandbox中library目录
@property (nonatomic, readonly) NSURL *libraryURL;
@property (nonatomic, readonly) NSString *libraryPath;

// 包名
@property (nullable, nonatomic, readonly) NSString *appBundleName;

// 包id
@property (nullable, nonatomic, readonly) NSString *appBundleID;

// App版本
@property (nullable, nonatomic, readonly) NSString *appVersion;

// App Build版本
@property (nullable, nonatomic, readonly) NSString *appBuildVersion;

// App不是从App Store下载的
@property (nonatomic, readonly) BOOL isPirated;

// 是否当前被调试中(debugger依附)
@property (nonatomic, readonly) BOOL isBeingDebugged;

// 当前线程的内存使用，出错返回-1
@property (nonatomic, readonly) int64_t memoryUsage;

// 当前线程的CPU使用，出错返回-1
@property (nonatomic, readonly) float cpuUsage;


/**
 提高NetworkActivity的计数（线程安全）
 
 当计数大于0的时候，会显示左上角系统的菊花
 当计数等于0的时候，会隐藏左上角系统的菊花
 */
- (void)incrementNetworkActivityCount;

/**
 提高NetworkActivity的计数(线程安全)
 
 当计数大于0的时候，会显示左上角系统的菊花
 当计数等于0的时候，会隐藏左上角系统的菊花
 */
- (void)decrementNetworkActivityCount;


// 是否是在App Extenstion中
+ (BOOL)isAppExtension;

// 和sharedApplication一样，不过在App Extensition返回nil
+ (nullable UIApplication *)sharedExtensionApplication;

@end

NS_ASSUME_NONNULL_END

