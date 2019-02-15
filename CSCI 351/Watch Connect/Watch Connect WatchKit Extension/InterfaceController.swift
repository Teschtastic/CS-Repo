//
//  InterfaceController.swift
//  Watch Connect WatchKit Extension
//
//  Created by Sean Tesch on 12/2/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import WatchKit
import Foundation
import WatchConnectivity


class InterfaceController: WKInterfaceController, WCSessionDelegate {
    @IBOutlet var msgLabel: WKInterfaceLabel!
    var session: WCSession!

    @IBAction func sendMsgToPhone() {
        if (WCSession.isSupported()) {
            session.sendMessage(["b":"goodbye"], replyHandler: nil, errorHandler: nil)
        }
    }
    
    func session(session: WCSession, didReceiveMessage message: [String : AnyObject]) {
        self.msgLabel.setText(message["a"]! as? String)
    }
    
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.
    }

    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
        if (WCSession.isSupported()) {
            self.session = WCSession.defaultSession()
            self.session.delegate = self
            self.session.activateSession()
        }
    }

    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }

}
