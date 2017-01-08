#!/usr/bin/env python
# Display a runtext with double-buffering.
from samplebase import SampleBase
from rgbmatrix import graphics
import time

class RunText(SampleBase):
    def __init__(self, request, *args, **kwargs):
        super(RunText, self).__init__(*args, **kwargs)
        self.request = request

    def Run(self):
        #Change to take request as a arguement. Request contains text,colour,font.
        offscreenCanvas = self.matrix.CreateFrameCanvas()
        font = graphics.Font()
        font.LoadFont("matrix/fonts/7x13.bdf")
        textColor = graphics.Color(255, 255, 0)
        pos = offscreenCanvas.width
        myText = request.json['text']

        while True:
            offscreenCanvas.Clear()
            len = graphics.DrawText(offscreenCanvas, font, pos, 10, textColor, myText)
            pos -= 1
            if (pos + len < 0):
                pos = offscreenCanvas.width

            time.sleep(0.05)
            offscreenCanvas = self.matrix.SwapOnVSync(offscreenCanvas)


# Main function
if __name__ == "__main__":
    print('bah')
    parser = RunText()
    if (not parser.process()):
        parser.print_help()
