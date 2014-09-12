//
//  PPRScheduler.h
//  ppreminderer
//
//  Created by David Bernard on 8/09/2014.
//  Copyright (c) 2014 Pegwing Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPRScheduleTime.h"
#import "PPRScheduledEvent.h"
#import "PPRSingleton.h"

@interface PPRScheduler : PPRSingleton

/**
 A dictionary of daily events.
 */
@property (nonatomic, strong) NSDictionary *dailyEvents;
/**
 A calendar for date calculations.
 */
@property (nonatomic, strong) NSCalendar *calendar;

/**
 Initialise with a list of daily events.
 @param dailyEvents A dictionary of daily events
 @return Initialised object or nil
 */
- (PPRScheduler *)initWithDailyEvents:(NSDictionary *)dailyEvents;

/**
 Caculate the due date for a scheduled time.
 @param scheduleTime A schedule time.
 @param parentDueTime The due time of the parent event
 @param previousDueTime The due time of a previous event in a list of events
 @return the due time
 */
- (NSDate *)dueTimeForScheduleTime: (PPRScheduleTime *)scheduleTime parentDueTime: (NSDate *)parentDueTime previousDueTime:(NSDate *)previousDueTime;
/**
 Helper function to create a date from date components specifying a time of day give a specific day.
 @param atTimeOfDay a date components object with the required components set.
 @param date a date used to calculate the start of day
 @return a date at the time of day
 */
- (NSDate *)dateAtTimeOfDay:(NSDateComponents *)atTimeOfDay date:(NSDate *)date;
@end