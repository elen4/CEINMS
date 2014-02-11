#!/usr/bin/env python3

import sys
import os
import shutil
import glob

def downsampleEmg(srcDirectory, dstDirectory):
    lmtFilename = "lmt.txt"
    emgFilename = "emg.txt"
    downSampledEmg = [];
    timecolumn = [];
    header = ''
    with open(srcDirectory+'/'+lmtFilename) as f:
        content = f.readlines()
        for line in content[3:]:
            timecolumn.append(line.split()[0])

    sampleTime = float(timecolumn[1])-float(timecolumn[0])
    sampleTime = int(sampleTime * 1000) / 1000.0
    
    with open(srcDirectory+'/'+emgFilename) as f:
        content = f.readlines()
        header = content[2];
        for index in range(0,len(content[3:])):
            result = float(content[3+index].split()[0])/sampleTime
            result = int(result * 1000) / 1000.0
            if (result.is_integer()):
                 downSampledEmg.append(content[3+index])   
 
        with open(dstDirectory+'/emg.txt', 'w') as outF:
            outF.write('datacolumns '+str(len(header.split()))+'\n')
            outF.write('datarows '+str(len(downSampledEmg))+'\n')
            outF.write(header)        
            for line in downSampledEmg:             
                outF.write(line)

def get_immediate_subdirectories(directory):
    return [name for name in os.listdir(directory)
            if os.path.isdir(os.path.join(directory, name))]



srcDirectory = sys.argv[1]
workingDir = os.getcwd()

for aDir in get_immediate_subdirectories(srcDirectory):
    dstDirectory = workingDir+'/'+aDir
    if not os.path.exists(dstDirectory):
        os.makedirs(dstDirectory)
#    glob.glob(srcDirectory+'/'+aDir+'/*.txt')
    for aFile in glob.glob(srcDirectory+'/'+aDir+'/*.txt'):
        shutil.copy(aFile, dstDirectory)
    
    downsampleEmg(srcDirectory+'/'+aDir, dstDirectory)







