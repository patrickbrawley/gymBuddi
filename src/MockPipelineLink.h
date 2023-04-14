#ifndef MOCKPIPELINELINK_H
#define MOCKPIPELINELINK_H

#include "PipelineLink.h"

class MockPipelineLink : public PipelineLink {
public:
    void NextScene(Scene& scene) override;
    void setCallback(PipelineLink* next) override;
    bool isCallbackSet() const override;
    bool isCalled() const;
private:
    PipelineLink* nextLink;
    bool called = false;
};

#endif