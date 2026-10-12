#include "MainComponent.h"

namespace amp
{
    MainComponent::MainComponent()
    {
        setSize (1280, 720);
    }

    void MainComponent::paint (juce::Graphics& g)
    {
        g.fillAll (juce::Colour (0xff121417));

        const auto centre = getLocalBounds().getCentre();

        g.setColour (juce::Colours::white);
        g.setFont (juce::FontOptions (40.0f, juce::Font::bold));
        g.drawText ("AUDIO MASTER PRO",
                    juce::Rectangle<int> (getWidth(), 60).withCentre (centre.translated (0, -20)),
                    juce::Justification::centred);

        g.setColour (juce::Colour (0xff8a93a0));
        g.setFont (juce::FontOptions (16.0f));
        g.drawText ("Professional Audio. Precision Loudness. One Platform.",
                    juce::Rectangle<int> (getWidth(), 30).withCentre (centre.translated (0, 25)),
                    juce::Justification::centred);
    }

    void MainComponent::resized() {}
}
