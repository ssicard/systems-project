import React, { Component } from 'react';
import Paper from '@material-ui/core/Paper';
import ArrowIcon from '@material-ui/icons/ArrowRightAlt';
import CaratIcon from '@material-ui/icons/KeyboardArrowDown';
import Collapse from '@material-ui/core/Collapse';
import Button from '@material-ui/core/Button';
import { connect } from 'react-redux';
import {selectLog, expandLog} from '../actions/LogActions';

class ParentLogEntry extends Component {
    styles = {
        entryInnerContainer: {
            display: "flex",
            padding:"5px",
            flexDirection:"row",
            flex:1,
        },
        entryDataLeftCell: {
            flex:2,
            paddingLeft: "10px",
            paddingRight: "10px",
            borderRight: "2px solid black",
            borderColor: "#85aef2",
            borderRadius: "2px",
            flexDirection: 'row',
            display:'flex'

        },
        entryDataMiddleCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
            flex: 4,
        },
        entryDataRightCell: {
            alignItems: "center",
            flexDirection: 'column',
        },
        label: {
            paddingBottom:'2px',
            color: '#AAAAAA',
            fontSize: '13px',
        },
        sourceDestContainer:{
            flex:2,
            display: 'flex',
            flexDirection: 'row',
            alignItems: 'center',
            justifyContent: 'center',
        },
        attribContainer:{
            alignItems: "center",
            flexDirection: 'column',
        }
    }
  getEntryContainerStyle = () =>{
      if(this.props.selectedLog==this.props.guid){
          return {marginBottom:'5px', border: '2px solid red', flexDirection: 'column', display:'flex'};
      } else {
          return {marginBottom: '5px',flexDirection: 'column', display:'flex'};
      }
  }
  getLeftCellStyle = () => {
    if(this.props.selectedLog == this.props.guid){
        return {...this.styles.entryDataLeftCell, borderColor:'red'};
    } else {
        return this.styles.entryDataLeftCell;
    }
  }
  getArrowIconStyle =()=>{
      if(this.props.selectedLog == this.props.guid){
          return {color: 'red'}
      } else {
          return {color: '#85aef2'}
      }
  }
  getLabelStyle = () => {
      if(this.props.selectedLog == this.props.guid){
          return {...this.styles.label,color:'red'};
      } else {
          return this.styles.label;
      }
  }
  selectLog = () => {
    if(this.props.selectedLog==this.props.guid){
        this.props.selectLog(-1);
    } else {
        this.props.selectLog(this.props.guid);
    }
  }
  render() {
    return (
        <div name="entryInnerContainer" style={this.styles.entryInnerContainer} onClick={this.selectLog}>
          <div name="time" style={this.getLeftCellStyle()}>
            <div style={this.styles.attribContainer}>
                <div style={this.getLabelStyle()}>
                    Time Received
                </div>
                <div>
                    {this.props.time}
                </div>
            </div>
          </div>
          <div name="sourceDestContainer" style={this.styles.sourceDestContainer}>
            <div name="sender" style={this.styles.entryDataMiddleCell}>
                    <div style={this.getLabelStyle()}>
                        Sender
                    </div>
                    <div>
                        {this.props.sender}
                    </div>
            </div>
            <div name="recipient" style={this.styles.entryDataRightCell}>
                    <div style={this.getLabelStyle()}>
                        Type
                    </div>
                    <div>
                        Request For Resource
                    </div>
            </div>
            <Button onClick={()=>{this.props.expandLog(this.props.guid)}}>
             <CaratIcon style={{color: '#85aef2'}}/>
            </Button>
          </div>
        </div>
    );
  }
}
const mapStateToProps = store =>{
    return {
        selectedLog: store.selectedLog.selectedLog
    };
}
export default connect(mapStateToProps, {selectLog, expandLog})(ParentLogEntry);
