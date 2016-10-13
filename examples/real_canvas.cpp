#include "../braille.hpp"
#include "../real_canvas.hpp"

#include <cmath>
#include <iostream>

using namespace plot;

int main() {
    RealCanvas<BrailleCanvas> canvas({ { 0.0f, 0.0f }, { 1.0f, 0.57f } }, Size(70, 20), TerminalInfo().detect());

    canvas.rect({ 1.0f, 0.35f, 0.0f }, { 0.0f, 0.2f, 1.0f }, { { 0.079f, 0.079f }, { 0.288f, 0.288f } })
          .push()
              .line({ 0.4f,  1.0f, 0.4f }, { 0.086f, 0.122f }, { 0.122f, 0.281f })
              .line({ 0.4f,  1.0f, 0.4f }, { 0.122f, 0.281f }, { 0.281f, 0.245f })
              .line({ 0.4f,  1.0f, 0.4f }, { 0.281f, 0.245f }, { 0.245f, 0.086f })
              .line({ 0.4f,  1.0f, 0.4f }, { 0.245f, 0.086f }, { 0.086f, 0.122f })
          .pop(TerminalOp::ClipDst)
          .ellipse({ 0.6f, 0.6f, 0.6f }, Rectf({ 0.216f, 0.216f }) + Pointf(0.324f, 0.079f))
          .ellipse({ 0, 0, 0 }, { 1.0f, 1.0f, 1.0f }, Rectf({ 0.144f, 0.144f }) + Pointf(0.3597f, 0.115f))
          .canvas().stroke({ 0.2f, 0.2f, 1.0f }, { { 12, 42 }, { 71, 67 } }, [](Coord x) {
              Coord base = 55 - std::lround(10*std::sin(2*3.141592f*((x - 12)/30.0f))),
                    end  = 55 - std::lround(10*std::sin(2*3.141592f*((x - 11)/30.0f)));
              return (base != end) ? std::make_pair(base, end) : std::make_pair(base, base+1);
          })
          .stroke({ 1.0f, 0.4f, 0.4f }, { { 12, 42 }, { 71, 67 } }, [](Coord x) {
              Coord base = 55 - std::lround(10*std::cos(2*3.141592f*((x - 12)/30.0f))),
                    end  = 55 - std::lround(10*std::cos(2*3.141592f*((x - 11)/30.0f)));
              return (base != end) ? std::make_pair(base, end) : std::make_pair(base, base+1);
          }, TerminalOp::ClipSrc);

    std::cout << canvas << std::endl;

    return 0;
}
