//
//  PPRClientAction.m
//  ppreminderer
//
//  Created by David Bernard on 9/09/2014.
//  Copyright (c) 2014 Pegwing Pty Ltd. All rights reserved.
//

#import "PPRClientAction.h"
#import "PPRClientInstruction.h"

@implementation PPRClientAction
-(id)initWithClient:(PPRClient *)client
{
    self = [super init];
    if (self) {
        _client = client;
    }
    return self;
}

- (NSArray *)instructionsForAction {
    NSIndexSet *instructionSet;
    instructionSet = [self.client.instructions
                      indexesOfObjectsPassingTest:^BOOL(id obj, NSUInteger idx, BOOL *stop) {
                          return [((PPRClientInstruction *)obj).context isEqualToString:self.context];
                      }];
    NSArray *instructions = [self.client.instructions objectsAtIndexes:instructionSet];
    
    return instructions;
}
@end
