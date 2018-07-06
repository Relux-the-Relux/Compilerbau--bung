//
//  main.swift
//  minako-test
//
//  Created by Zhirui Dai on 2018/7/5.
//  Copyright © 2018 Zhirui Dai. All rights reserved.
//

import Foundation

func test(fileName: String) -> (String, String) {
    let process = Process()
    let stdout = Pipe()
    let stderr = Pipe()
    
    process.executableURL = URL(fileURLWithPath: "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako")
    process.arguments = [fileName]
    process.standardOutput = stdout
    process.standardError = stderr
    
    process.launch()
    
//    let stdoutString = String(data: stdout.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8)
    let stderrString = String(data: stderr.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8)
    
//    print("STDOUT:")
//    print(stdoutString ?? "")
//    print("STDERR:")
//    print(stderrString ?? "")
    
    return ("", stderrString ?? "")
}

guard let regex: NSRegularExpression = try? NSRegularExpression(pattern: "\"Error in line\"\\.*", options: .caseInsensitive)
    else {
        print("Fail to generate a regular expression")
        exit(EXIT_FAILURE)
}

let testSuitURL = URL(fileURLWithPath: "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako-test/testsuite", isDirectory: true)

guard let correctTestFiles = FileManager.default.subpaths(atPath: testSuitURL.appendingPathComponent("cor").relativePath) else { exit(EXIT_FAILURE) }
guard let errorTestFiles = FileManager.default.subpaths(atPath: testSuitURL.appendingPathComponent("err").relativePath) else { exit(EXIT_FAILURE) }

for file in correctTestFiles {
    print("TEST: \(file)")
    let (stdout, stderr) = test(fileName: testSuitURL.appendingPathComponent("cor").appendingPathComponent(file).relativePath)
    if stderr.lowercased().contains("error") {
        fatalError("Test fail: \(file)")
    }
}

for file in errorTestFiles {
    print("TEST: \(file)")
    let (stdout, stderr) = test(fileName: testSuitURL.appendingPathComponent("err").appendingPathComponent(file).relativePath)
    if !stderr.lowercased().contains("error") {
        
        fatalError("Test fail: \(file)")
    } else {
        let matches = regex.matches(in: stderr, options: [.reportCompletion], range: NSMakeRange(0, stderr.count))
        for match in matches {
            print((stderr as NSString).substring(with: match.range))
        }
    }
}


