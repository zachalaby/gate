/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== PluginProcessor.cpp ==================
static const unsigned char temp_binary_data_0[] =
"/*\r\n"
"  ==============================================================================\r\n"
"\r\n"
"    This file was auto-generated!\r\n"
"\r\n"
"    It contains the basic framework code for a JUCE plugin processor.\r\n"
"\r\n"
"  ==============================================================================\r\n"
"*/\r\n"
"\r\n"
"#include \"PluginProcessor.h\"\r\n"
"#include \"PluginEditor.h\"\r\n"
"#include \"./../../../lib/fftw/fftw-3.3.5/api/fftw3.h\"\r\n"
"\r\n"
"\r\n"
"//==============================================================================\r\n"
"GateAndKeyAudioProcessor::GateAndKeyAudioProcessor()\r\n"
"#ifndef JucePlugin_PreferredChannelConfigurations\r\n"
"     : AudioProcessor (BusesProperties()\r\n"
"                     #if ! JucePlugin_IsMidiEffect\r\n"
"                      #if ! JucePlugin_IsSynth\r\n"
"                       .withInput  (\"Input\",  AudioChannelSet::stereo(), true)\r\n"
"                      #endif\r\n"
"                       .withOutput (\"Output\", AudioChannelSet::stereo(), true)\r\n"
"                     #endif\r\n"
"                       )\r\n"
"#endif\r\n"
"{\r\n"
"}\r\n"
"\r\n"
"GateAndKeyAudioProcessor::~GateAndKeyAudioProcessor()\r\n"
"{\r\n"
"}\r\n"
"\r\n"
"//==============================================================================\r\n"
"const String GateAndKeyAudioProcessor::getName() const\r\n"
"{\r\n"
"    return JucePlugin_Name;\r\n"
"}\r\n"
"\r\n"
"bool GateAndKeyAudioProcessor::acceptsMidi() const\r\n"
"{\r\n"
"   #if JucePlugin_WantsMidiInput\r\n"
"    return true;\r\n"
"   #else\r\n"
"    return false;\r\n"
"   #endif\r\n"
"}\r\n"
"\r\n"
"bool GateAndKeyAudioProcessor::producesMidi() const\r\n"
"{\r\n"
"   #if JucePlugin_ProducesMidiOutput\r\n"
"    return true;\r\n"
"   #else\r\n"
"    return false;\r\n"
"   #endif\r\n"
"}\r\n"
"\r\n"
"double GateAndKeyAudioProcessor::getTailLengthSeconds() const\r\n"
"{\r\n"
"    return 0.0;\r\n"
"}\r\n"
"\r\n"
"int GateAndKeyAudioProcessor::getNumPrograms()\r\n"
"{\r\n"
"    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,\r\n"
"                // so this should be at least 1, even if you're not really implementing programs.\r\n"
"}\r\n"
"\r\n"
"int GateAndKeyAudioProcessor::getCurrentProgram()\r\n"
"{\r\n"
"    return 0;\r\n"
"}\r\n"
"\r\n"
"void GateAndKeyAudioProcessor::setCurrentProgram (int index)\r\n"
"{\r\n"
"}\r\n"
"\r\n"
"const String GateAndKeyAudioProcessor::getProgramName (int index)\r\n"
"{\r\n"
"    return String();\r\n"
"}\r\n"
"\r\n"
"void GateAndKeyAudioProcessor::changeProgramName (int index, const String& newName)\r\n"
"{\r\n"
"}\r\n"
"\r\n"
"//==============================================================================\r\n"
"void GateAndKeyAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)\r\n"
"{\r\n"
"    // Use this method as the place to do any pre-playback\r\n"
"    // initialisation that you need..\r\n"
"}\r\n"
"\r\n"
"void GateAndKeyAudioProcessor::releaseResources()\r\n"
"{\r\n"
"    // When playback stops, you can use this as an opportunity to free up any\r\n"
"    // spare memory, etc.\r\n"
"}\r\n"
"\r\n"
"#ifndef JucePlugin_PreferredChannelConfigurations\r\n"
"bool GateAndKeyAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const\r\n"
"{\r\n"
"  #if JucePlugin_IsMidiEffect\r\n"
"    ignoreUnused (layouts);\r\n"
"    return true;\r\n"
"  #else\r\n"
"    // This is the place where you check if the layout is supported.\r\n"
"    // In this template code we only support mono or stereo.\r\n"
"    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()\r\n"
"     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())\r\n"
"        return false;\r\n"
"\r\n"
"    // This checks if the input layout matches the output layout\r\n"
"   #if ! JucePlugin_IsSynth\r\n"
"    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())\r\n"
"        return false;\r\n"
"   #endif\r\n"
"\r\n"
"    return true;\r\n"
"  #endif\r\n"
"}\r\n"
"#endif\r\n"
"\r\n"
"void GateAndKeyAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)\r\n"
"{\r\n"
"    const int totalNumInputChannels  = getTotalNumInputChannels();\r\n"
"    const int totalNumOutputChannels = getTotalNumOutputChannels();\r\n"
"\r\n"
"    // In case we have more outputs than inputs, this code clears any output\r\n"
"    // channels that didn't contain input data, (because these aren't\r\n"
"    // guaranteed to be empty - they may contain garbage).\r\n"
"    // This is here to avoid people getting screaming feedback\r\n"
"    // when they first compile a plugin, but obviously you don't need to keep\r\n"
"    // this code if your algorithm always overwrites all the output channels.\r\n"
"    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)\r\n"
"        buffer.clear (i, 0, buffer.getNumSamples());\r\n"
"\r\n"
"    // This is the place where you'd normally do the guts of your plugin's\r\n"
"    // audio processing...\r\n"
"    for (int channel = 0; channel < totalNumInputChannels; ++channel)\r\n"
"    {\r\n"
"        float* channelData = buffer.getWritePointer (channel);\r\n"
"        \r\n"
"        for(int sample = 0; sample < buffer.getNumSamples(); sample++) {\r\n"
"            \r\n"
"            channelData[sample] = 0.0f;\r\n"
"            \r\n"
"        }\r\n"
"        \r\n"
"    }\r\n"
"}\r\n"
"\r\n"
"//==============================================================================\r\n"
"bool GateAndKeyAudioProcessor::hasEditor() const\r\n"
"{\r\n"
"    return true; // (change this to false if you choose to not supply an editor)\r\n"
"}\r\n"
"\r\n"
"AudioProcessorEditor* GateAndKeyAudioProcessor::createEditor()\r\n"
"{\r\n"
"    return new GateAndKeyAudioProcessorEditor (*this);\r\n"
"}\r\n"
"\r\n"
"//==============================================================================\r\n"
"void GateAndKeyAudioProcessor::getStateInformation (MemoryBlock& destData)\r\n"
"{\r\n"
"    // You should use this method to store your parameters in the memory block.\r\n"
"    // You could do that either as raw data, or use the XML or ValueTree classes\r\n"
"    // as intermediaries to make it easy to save and load complex data.\r\n"
"}\r\n"
"\r\n"
"void GateAndKeyAudioProcessor::setStateInformation (const void* data, int sizeInBytes)\r\n"
"{\r\n"
"    // You should use this method to restore your parameters from this memory block,\r\n"
"    // whose contents will have been created by the getStateInformation() call.\r\n"
"}\r\n"
"\r\n"
"//==============================================================================\r\n"
"// This creates new instances of the plugin..\r\n"
"AudioProcessor* JUCE_CALLTYPE createPluginFilter()\r\n"
"{\r\n"
"    return new GateAndKeyAudioProcessor();\r\n"
"}\r\n";

const char* PluginProcessor_cpp = (const char*) temp_binary_data_0;

//================== PluginEditor.cpp ==================
static const unsigned char temp_binary_data_1[] =
"/*\r\n"
"  ==============================================================================\r\n"
"\r\n"
"    This file was auto-generated!\r\n"
"\r\n"
"    It contains the basic framework code for a JUCE plugin editor.\r\n"
"\r\n"
"  ==============================================================================\r\n"
"*/\r\n"
"\r\n"
"#include \"PluginProcessor.h\"\r\n"
"#include \"PluginEditor.h\"\r\n"
"\r\n"
"\r\n"
"//==============================================================================\r\n"
"GateAndKeyAudioProcessorEditor::GateAndKeyAudioProcessorEditor (GateAndKeyAudioProcessor& p)\r\n"
"    : AudioProcessorEditor (&p), processor (p)\r\n"
"{\r\n"
"    // Make sure that before the constructor has finished, you've set the\r\n"
"    // editor's size to whatever you need it to be.\r\n"
"    setSize (400, 300);\r\n"
"}\r\n"
"\r\n"
"GateAndKeyAudioProcessorEditor::~GateAndKeyAudioProcessorEditor()\r\n"
"{\r\n"
"}\r\n"
"\r\n"
"//==============================================================================\r\n"
"void GateAndKeyAudioProcessorEditor::paint (Graphics& g)\r\n"
"{\r\n"
"    g.fillAll (Colours::white);\r\n"
"\r\n"
"    g.setColour (Colours::black);\r\n"
"    g.setFont (15.0f);\r\n"
"    g.drawFittedText (\"Hello World!\", getLocalBounds(), Justification::centred, 1);\r\n"
"}\r\n"
"\r\n"
"void GateAndKeyAudioProcessorEditor::resized()\r\n"
"{\r\n"
"    // This is generally where you'll want to lay out the positions of any\r\n"
"    // subcomponents in your editor..\r\n"
"}\r\n";

const char* PluginEditor_cpp = (const char*) temp_binary_data_1;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x687677e3:  numBytes = 5915; return PluginProcessor_cpp;
        case 0xd36ebf84:  numBytes = 1300; return PluginEditor_cpp;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "PluginProcessor_cpp",
    "PluginEditor_cpp"
};

}
