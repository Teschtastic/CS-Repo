//
//  ViewController.swift
//  Watch Connect
//
//  Created by Sean Tesch on 12/2/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import WatchConnectivity

class ViewController: UIViewController, WCSessionDelegate {
    @IBOutlet weak var msgLabel: UILabel!
    var session: WCSession!

    @IBAction func sendMsgToWatch(sender: AnyObject) {
        session.sendMessage(["a":"hello"], replyHandler: nil, errorHandler: nil)
    }
    
    func session(session: WCSession, didReceiveMessage message: [String : AnyObject]) {
        self.msgLabel.text = message["b"]! as? String
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        if (WCSession.isSupported()) {
            self.session = WCSession.defaultSession()
            self.session.delegate = self
            self.session.activateSession()
        }
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

