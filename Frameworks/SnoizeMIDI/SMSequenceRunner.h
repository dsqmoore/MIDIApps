//
// Copyright 2001-2002 Kurt Revis. All rights reserved.
//

#import <OmniFoundation/OFObject.h>
#import <Foundation/Foundation.h>
#import <CoreMIDI/CoreMIDI.h>
#import <SnoizeMIDI/SMMessageDestinationProtocol.h>
#import <SnoizeMIDI/SMPeriodicTimer.h>

@class SMSequence;


@interface SMSequenceRunner : OFObject <SMPeriodicTimerListener>
{
    id<SMMessageDestination> nonretainedMessageDestination;

    SMSequence *sequence;

    Float64 tempo;
    MIDITimeStamp beatDuration;
    NSLock *tempoLock;

    struct {
        unsigned int sendsMIDIClock:1;
        unsigned int isRunning:1;
    } flags;

    Float64 currentBeat;
    MIDITimeStamp currentTime;
    
    NSMutableArray *playingNotes;
    NSLock *playingNotesLock;
}

- (id<SMMessageDestination>)messageDestination;
- (void)setMessageDestination:(id<SMMessageDestination>)value;

- (Float64)tempo;
- (void)setTempo:(Float64)value;

- (SMSequence *)sequence;
- (void)setSequence:(SMSequence *)value;

- (BOOL)sendsMIDIClock;
- (void)setSendsMIDIClock:(BOOL)value;

- (void)start;
- (void)stop;
- (BOOL)isRunning;

@end