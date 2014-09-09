//
//  PPRClientManager.h
//  ppreminderer
//
//  Created by David Bernard on 22/08/2014.
//  Copyright (c) 2014 Pegwing Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PPRClientManager : NSObject
+ (PPRClientManager *) sharedClient;
- (void)getClient:(NSDictionary *) client success:(void (^)(NSArray *)) success failure:(void (^)(NSError *)) failure;
@end
