//
//  main.swift
//  minako-test
//
//  Created by Zhirui Dai on 2018/7/5.
//  Copyright © 2018 Zhirui Dai. All rights reserved.
//

import Foundation

let process = Process()
let stdout = Pipe()
let stderr = Pipe()

process.executableURL = URL(fileURLWithPath: "/Users/daizhirui/Library/Developer/Xcode/DerivedData/minako-avgoakbfccbmxldokmhfqubodzew/Build/Products/Debug/minako")
process.arguments = ["/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako-test/testsuite/test-err-sem-main-06.c1"]
process.standardOutput = stdout
process.standardError = stderr

process.launch()

let stdoutString = String(data: stdout.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8)
let stderrString = String(data: stderr.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8)

print("STDOUT:")
print(stdoutString ?? "")
print("STDERR:")
print(stderrString ?? "")

