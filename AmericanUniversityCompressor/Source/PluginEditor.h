/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "AudioMeter.h"



//==============================================================================
/**
*/
class AmericanUniversityCompressorAudioProcessorEditor  : public AudioProcessorEditor,
                                                          public Slider::Listener,
                                                          private Timer
{
public:
    AmericanUniversityCompressorAudioProcessorEditor (AmericanUniversityCompressorAudioProcessor&);
    ~AmericanUniversityCompressorAudioProcessorEditor();


    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    void timerCallback() override;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AmericanUniversityCompressorAudioProcessor& processor;
    
    // MARK: Sliders & Knobs for the Compressor
    Slider makeupGain;
    Label makeupGainLabel;
    
    Slider attackTime;
    Label attackTimeLabel;
    
    Slider releaseTime;
    Label releaseTimeLabel;
    
    Slider ratio;
    Label ratioLabel;
    
    Slider threshold;
    Label thresholdLabel;
        
    AudioMeter rmsValue;
    Label rmsValueLabel;
    
    AudioMeter rms2DBValue;
    Label rms2DBValueLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmericanUniversityCompressorAudioProcessorEditor)
};
