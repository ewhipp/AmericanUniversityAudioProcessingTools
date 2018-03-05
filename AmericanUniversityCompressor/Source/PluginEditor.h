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
                                                          private Timer
{
public:
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    enum
    {
        parameterControlHeight = 40,
        paramaterControlLabelWidth = 80,
        parameterControlWidth = 300
    };
    
    AmericanUniversityCompressorAudioProcessorEditor (AmericanUniversityCompressorAudioProcessor&, AudioProcessorValueTreeState&);
    ~AmericanUniversityCompressorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;
    
private:
    AmericanUniversityCompressorAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    
    Label makeupGainLabel;
    Slider makeupGainSlider;
    ScopedPointer<SliderAttachment> makeupAttachment;
    
    Label attackLabel;
    Slider attackSlider;
    ScopedPointer<SliderAttachment> attackAttachment;
    
    Label thresholdLabel;
    Slider thresholdSlider;
    ScopedPointer<SliderAttachment> thresholdAttachment;
    
    Label releaseLabel;
    Slider releaseSlider;
    ScopedPointer<SliderAttachment> releaseAttachment;
    
    Label ratioLabel;
    Slider ratioSlider;
    ScopedPointer<SliderAttachment> ratioAttachment;
   
    AudioMeter rmsValue;
    Label rmsValueLabel;
    
    AudioMeter rms2DBValue;
    Label rms2DBValueLabel;
    Label currentGainEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmericanUniversityCompressorAudioProcessorEditor)
};
