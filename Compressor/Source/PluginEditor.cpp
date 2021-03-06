/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/


#include "PluginEditor.h"

//==============================================================================
CompressorAudioProcessorEditor::CompressorAudioProcessorEditor (CompressorAudioProcessor& parent)
:   AudioProcessorEditor (&parent),
    m_processor          (parent),
    m_makeupGainSlider   (Slider::LinearVertical, Slider::TextBoxBelow),
    m_thresholdSlider    (Slider::LinearVertical, Slider::TextBoxBelow),
    m_attackSlider       (Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow),
    m_releaseSlider      (Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow),
    m_ratioSlider        (Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow),
    m_kneeButton         ("Toggle Knee"),
    m_signalStreamViewer (m_processor.getTotalNumInputChannels())
{
    typedef CompressorAudioProcessor::CompressorParameters compParams;
    m_tooltipWindow->setMillisecondsBeforeTipAppears (1000);
    
    m_attackLabel.setText(translate ("Attack"), dontSendNotification);
    addAndMakeVisible (m_attackLabel);
    addAndMakeVisible (m_attackSlider);
    m_sliderAttachments.add (new SliderAttachment (m_processor.getPluginState(), m_processor.getParameterId (compParams::ATTACK), m_attackSlider));
    m_attackSlider.setTooltip ("Attack time");
    
    m_releaseLabel.setText (translate ("Release"), dontSendNotification);
    addAndMakeVisible (m_releaseLabel);
    addAndMakeVisible (m_releaseSlider);
    m_sliderAttachments.add (new SliderAttachment (m_processor.getPluginState(), m_processor.getParameterId (compParams::RELEASE), m_releaseSlider));
    m_releaseSlider.setTooltip ("Release Time");
    
    m_ratioLabel.setText (translate ("Ratio"), dontSendNotification);
    addAndMakeVisible (m_ratioLabel);
    addAndMakeVisible (m_ratioSlider);
    m_sliderAttachments.add (new SliderAttachment (m_processor.getPluginState(), m_processor.getParameterId (compParams::RATIO), m_ratioSlider));
    m_ratioSlider.setTooltip ("Ratio of Compression");
    
    m_makeupGainLabel.setText(translate ("Make-up"), dontSendNotification);
    addAndMakeVisible (m_makeupGainLabel);
    addAndMakeVisible (m_makeupGainSlider);
    m_sliderAttachments.add (new SliderAttachment (m_processor.getPluginState(), m_processor.getParameterId (compParams::MAKEUPGAIN), m_makeupGainSlider));
    m_makeupGainSlider.setTooltip ("Make-up gain");
    
    m_thresholdLabel.setText(translate ("Threshold"), dontSendNotification);
    addAndMakeVisible(m_thresholdLabel);
    addAndMakeVisible(m_thresholdSlider);
    m_sliderAttachments.add (new SliderAttachment (m_processor.getPluginState(), m_processor.getParameterId (compParams::THRESHOLD), m_thresholdSlider));
    m_thresholdSlider.setTooltip ("Threshold of compression");
    
    addAndMakeVisible (m_kneeButton);
    m_buttonAttachments.add (new ButtonAttachment (m_processor.getPluginState(), m_processor.getParameterId (compParams::KNEE), m_kneeButton));
    m_kneeButton.setTooltip ("Engage hard knee");
    
    m_signalStreamViewer.setNumChannels (2);
    m_signalStreamViewer.setColours (Colours::black, Colours::green);
    m_signalStreamViewer.setRepaintRate (30);
    addAndMakeVisible (m_signalStreamViewer);
    
    m_levelMeter = std::make_unique <Meter> (IMeter::METER_TYPE::LEVEL, -100.0f, 0.0f);
    addAndMakeVisible (m_levelMeter.get());
    
    m_engagementMeter = std::make_unique <Meter> (IMeter::METER_TYPE::ENGAGEMENT);
    addAndMakeVisible (m_engagementMeter.get());
    
    DropShadow engagementMeterShadow;
    DropShadow levelMeterShadow;
    m_engagementShadower    = std::make_unique <DropShadower> (engagementMeterShadow);
    m_levelShadower         = std::make_unique <DropShadower> (levelMeterShadow);
    m_engagementShadower->setOwner (m_engagementMeter.get());
    m_levelShadower->setOwner (m_levelMeter.get());
    
    m_processor.addChangeListener (this);
    startTimerHz(30);
    setSize(580, 350);
}

CompressorAudioProcessorEditor::~CompressorAudioProcessorEditor() { }

/*
 * Updates:
 *  - The signal stream viewer.
 *  - The level meter.
 *  - The engagement meter.
 *
 * @see: Meter
 */
void CompressorAudioProcessorEditor::timerCallback()
{
    m_signalStreamViewer.pushBuffer (m_processor.getVisualBuffer());
    m_levelMeter->setIncomingSignal (m_processor.getCurrentdB());
    
    if (m_processor.getCurrentRMS() > m_processor.getCurrentThresholdRMS())
        m_engagementMeter->setIncomingSignal (m_processor.getCurrentOvershoot());
    else
        m_engagementMeter->setIncomingSignal (0.0f);
}

//==============================================================================
void CompressorAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::white);
    g.setFont (12.0f);
}

void CompressorAudioProcessorEditor::resized()
{
    Rectangle<int> pluginWindow = getLocalBounds();
    Rectangle<int> sliderLabelArea = pluginWindow.removeFromTop (50);
    
    m_levelMeter->setBounds (pluginWindow.removeFromLeft (25));
    pluginWindow.removeFromLeft (10);
    m_kneeButton.setBounds (sliderLabelArea.removeFromLeft (100));
    m_engagementMeter->setBounds (pluginWindow.removeFromLeft (50).removeFromTop (50));
    
    m_thresholdLabel.setBounds   (sliderLabelArea.removeFromLeft (100));
    m_thresholdSlider.setBounds  (pluginWindow.removeFromLeft (100));
    
    m_makeupGainLabel.setBounds  (sliderLabelArea.removeFromRight (70));
    m_makeupGainSlider.setBounds (pluginWindow.removeFromRight (80));
    
    Rectangle<int> parameterArea =      pluginWindow.removeFromBottom (100);
    Rectangle<int> parameterLabelArea = pluginWindow.removeFromBottom (25);
    
    m_ratioLabel.setBounds    (parameterLabelArea.removeFromRight (70));
    m_ratioSlider.setBounds   (parameterArea.removeFromRight (100));
    
    m_attackLabel.setBounds   (parameterLabelArea.removeFromRight (100));
    m_attackSlider.setBounds  (parameterArea.removeFromRight (100));
    
    m_releaseLabel.setBounds  (parameterLabelArea.removeFromRight (110));
    m_releaseSlider.setBounds (parameterArea.removeFromRight (100));
    
        
    m_signalStreamViewer.setBounds (172, 30, (getWidth() / 2) + 50, (getHeight() / 2) + 20);
}

void CompressorAudioProcessorEditor::changeListenerCallback(ChangeBroadcaster* sender)
{
    ignoreUnused (sender);
    repaint();
}
