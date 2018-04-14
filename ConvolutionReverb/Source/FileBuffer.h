/*
  ==============================================================================

    FileReader.h
    Created: 1 Apr 2018 10:50:38am
    Author:  Erik Whipp

    This class is responsible for allowing us to multithread where we
    place our convolution files. Otherwise, we will have problems with
    glitches.
  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class FileBuffer : public ReferenceCountedObject
{
public: 
    typedef ReferenceCountedObjectPtr <FileBuffer> Ptr;

    
    FileBuffer     (const String& nameToUse,
                            int numChannels,
                            int numSamples) :
    name (nameToUse),
    buffer (numChannels, numSamples)
    {
        DBG (String ("Buffer named '") + name + "' created. numChannels = " + 
        String (numChannels) + ", numSamples " + String (numSamples));
    }
    
    ~FileBuffer()
    {
        DBG (String ("Buffer named '") + name + "' destroyed");
    }
    
    AudioSampleBuffer* getAudioSampleBuffer()
    {
        return &buffer;
    }

    int pos = 0;
    
private:
    String name;
    AudioSampleBuffer buffer;
    FileBuffer::Ptr currentAudioBuffer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileBuffer)
};