/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
//#include "./../../../lib/fftw/fftw-3.3.5/api/fftw3.h"



//==============================================================================
GateAndKeyAudioProcessor::GateAndKeyAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

GateAndKeyAudioProcessor::~GateAndKeyAudioProcessor()
{
}

//==============================================================================
const String GateAndKeyAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GateAndKeyAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GateAndKeyAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double GateAndKeyAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GateAndKeyAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GateAndKeyAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GateAndKeyAudioProcessor::setCurrentProgram (int index)
{
}

const String GateAndKeyAudioProcessor::getProgramName (int index)
{
    return String();
}

void GateAndKeyAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GateAndKeyAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void GateAndKeyAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GateAndKeyAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void GateAndKeyAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages) {
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    const float thresh = .05;
    
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    
    
    
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        if(buffer.getRMSLevel(channel, 0, buffer.getNumSamples()) < thresh) {
            std::cout << "cleared";
            buffer.clear();
        } else {
            std::cout << buffer.getRMSLevel(channel, 0, buffer.getNumSamples());
        }
        
        
//        float* channelData = buffer.getWritePointer (channel);
//        for(int sample = 0; sample < buffer.getNumSamples(); sample++) {
//            
//
//            channelData[sample] = 0.0f;
//            
//        }
        
    }
}

//==============================================================================
bool GateAndKeyAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GateAndKeyAudioProcessor::createEditor()
{
    return new GateAndKeyAudioProcessorEditor (*this);
}

//==============================================================================
void GateAndKeyAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GateAndKeyAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GateAndKeyAudioProcessor();
}
