/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
class CompressorAudioProcessorEditor  : public AudioProcessorEditor,
                                                          public ChangeListener,
                                                          private Timer
{
public:
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    CompressorAudioProcessorEditor (CompressorAudioProcessor&);
    ~CompressorAudioProcessorEditor();

    //==============================================================================
    
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;
    void changeListenerCallback(ChangeBroadcaster* sender) override;
    
private:
    CompressorAudioProcessor& m_processor;
    
    Label       m_makeupGainLabel;
    Slider      m_makeupGainSlider;
    
    Label       m_thresholdLabel;
    Slider      m_thresholdSlider;
    
    Label       m_attackLabel;
    Slider      m_attackSlider;
    
    Label       m_releaseLabel;
    Slider      m_releaseSlider;
    
    Label       m_ratioLabel;
    Slider      m_ratioSlider;
    
    TextButton  m_kneeButton;
    
    OwnedArray <SliderAttachment> m_attachments;
    SharedResourcePointer <TooltipWindow> m_tooltipWindow;
        
    AudioVisualiserComponent m_signalStreamViewer;
    
   /* std::unique_ptr<AudioMeter> rmsValue;
    Label rmsValueLabel;
    
    std::unique_ptr<AudioMeter> dBMeter;
    Label dBMeterLabel; */
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressorAudioProcessorEditor)
};
