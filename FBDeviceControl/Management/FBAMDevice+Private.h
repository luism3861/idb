/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <FBDeviceControl/FBAMDevice.h>
#import <FBDeviceControl/FBAMDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class FBAFCConnection;
@class FBAMDServiceConnection;
@class FBAMDeviceServiceManager;

#pragma mark - AMDevice Class Private

@interface FBAMDevice () <FBFutureContextManagerDelegate>

#pragma mark Properties

/**
 The AMDevice Reference
 */
@property (nonatomic, assign, readwrite) AMDeviceRef amDevice;

/**
 All of the Device Values available.
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString *, id> *allValues;

/**
 The Context Manager for the Connection
 */
@property (nonatomic, strong, readonly) FBFutureContextManager<FBAMDevice *> *connectionContextManager;

/**
 The Service Manager.
 */
@property (nonatomic, strong, readonly) FBAMDeviceServiceManager *serviceManager;

/**
 The AMDCalls to be used.
 */
@property (nonatomic, assign, readonly) AMDCalls calls;

/**
 The Queue on which work should be performed.
 */
@property (nonatomic, strong, readonly) dispatch_queue_t workQueue;

/**
 The logger to log to.
 */
@property (nonatomic, strong, readonly) id<FBControlCoreLogger> logger;

#pragma mark Private Methods

/**
 The Designated Initializer

 @param udid the UDID of the AMDevice.
 @param allValues the values from the AMDevice.
 @param calls the calls to use.
 @param connectionReuseTimeout the time to wait before releasing a connection
 @param serviceReuseTimeout the time to wait before releasing a service
 @param workQueue the queue to perform work on.
 @param logger the logger to use.
 @return a new FBAMDevice instance.
 */
- (instancetype)initWithUDID:(NSString *)udid allValues:(NSDictionary<NSString *, id> *)allValues calls:(AMDCalls)calls connectionReuseTimeout:(nullable NSNumber *)connectionReuseTimeout serviceReuseTimeout:(nullable NSNumber *)serviceReuseTimeout workQueue:(dispatch_queue_t)workQueue logger:(id<FBControlCoreLogger>)logger;

@end

NS_ASSUME_NONNULL_END
